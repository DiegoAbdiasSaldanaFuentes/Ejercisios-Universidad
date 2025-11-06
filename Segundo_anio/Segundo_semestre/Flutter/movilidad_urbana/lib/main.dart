import 'dart:async';
import 'dart:math';

import 'package:flutter/material.dart';

void main() {
  runApp(const MyApp());
}

/// Modelo simple para un taxi/colectivo
class Taxi {
  Taxi({
    required this.id,
    required this.plate,
    required this.company,
    required this.position,
    required this.availableSeats,
    this.isActive = false,
  });

  final String id;
  final String plate;
  final String company;
  Offset position; // posición simulada en "mapa" (valores 0..1)
  int availableSeats;
  bool isActive;

  Taxi copyWith({Offset? position, int? availableSeats, bool? isActive}) {
    return Taxi(
      id: id,
      plate: plate,
      company: company,
      position: position ?? this.position,
      availableSeats: availableSeats ?? this.availableSeats,
      isActive: isActive ?? this.isActive,
    );
  }
}

/// Servicio que simula datos en tiempo real.
/// En producción reemplazar por Firebase / WebSocket y lógica de geolocalización.
class TaxiService {
  TaxiService._internal() {
    _init();
  }
  static final TaxiService _instance = TaxiService._internal();
  factory TaxiService() => _instance;

  final _rand = Random();
  final StreamController<List<Taxi>> _controller =
      StreamController<List<Taxi>>.broadcast();

  // taxis simulados
  final List<Taxi> _taxis = [
    Taxi(
      id: 't1',
      plate: 'AB-1234',
      company: 'Colectivo Norte',
      position: const Offset(0.2, 0.3),
      availableSeats: 2,
      isActive: true,
    ),
    Taxi(
      id: 't2',
      plate: 'CD-5678',
      company: 'Colectivo Sur',
      position: const Offset(0.7, 0.5),
      availableSeats: 0,
      isActive: true,
    ),
  ];

  Timer? _simTimer;

  Stream<List<Taxi>> get taxisStream => _controller.stream;

  List<Taxi> get current => List.unmodifiable(_taxis);

  void _init() {
    // Emite estado inicial
    _controller.add(current);

    // Simula movimiento leve cada 2 segundos
    _simTimer = Timer.periodic(const Duration(seconds: 2), (_) {
      for (var i = 0; i < _taxis.length; i++) {
        final t = _taxis[i];
        if (!t.isActive) continue;
        final dx = (_rand.nextDouble() - 0.5) * 0.04;
        final dy = (_rand.nextDouble() - 0.5) * 0.04;
        final newPos = Offset(
          (t.position.dx + dx).clamp(0.02, 0.98),
          (t.position.dy + dy).clamp(0.02, 0.98),
        );
        _taxis[i] = t.copyWith(position: newPos);
      }
      _controller.add(current);
    });
  }

  // Actualiza disponibilidad de un taxi
  void updateSeats(String id, int seats) {
    final idx = _taxis.indexWhere((t) => t.id == id);
    if (idx == -1) return;
    _taxis[idx] = _taxis[idx].copyWith(availableSeats: seats);
    _controller.add(current);
  }

  // Activa/desactiva taxi
  void setActive(String id, bool active) {
    final idx = _taxis.indexWhere((t) => t.id == id);
    if (idx == -1) return;
    _taxis[idx] = _taxis[idx].copyWith(isActive: active);
    _controller.add(current);
  }

  // Crea un nuevo taxi (simula alta de chofer)
  void addTaxi(Taxi taxi) {
    _taxis.add(taxi);
    _controller.add(current);
  }

  // Simula recorrido guiado: mueve taxi por una lista de puntos
  Future<void> simulateRoute(
    String id,
    List<Offset> route, {
    Duration step = const Duration(seconds: 1),
  }) async {
    final idx = _taxis.indexWhere((t) => t.id == id);
    if (idx == -1) return;
    setActive(id, true);
    for (final p in route) {
      await Future.delayed(step);
      // actualiza posición
      final currentTaxi = _taxis[idx];
      _taxis[idx] = currentTaxi.copyWith(position: p);
      _controller.add(current);
    }
    // al terminar, marca como inactivo
    setActive(id, false);
  }

  void dispose() {
    _simTimer?.cancel();
    _controller.close();
  }
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Simulador Colectivos',
      theme: ThemeData(primarySwatch: Colors.blue),
      home: const MainTabs(),
    );
  }
}

/// Pantallas principales: Pasajero y Chofer
class MainTabs extends StatefulWidget {
  const MainTabs({super.key});

  @override
  State<MainTabs> createState() => _MainTabsState();
}

class _MainTabsState extends State<MainTabs> {
  int _index = 0;
  final pages = const [PassengerPage(), DriverPage()];

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('Movilidad Urbana - Simulación'),
        centerTitle: true,
      ),
      body: pages[_index],
      bottomNavigationBar: BottomNavigationBar(
        currentIndex: _index,
        onTap: (v) => setState(() => _index = v),
        items: const [
          BottomNavigationBarItem(icon: Icon(Icons.person), label: 'Pasajero'),
          BottomNavigationBarItem(icon: Icon(Icons.drive_eta), label: 'Chofer'),
        ],
      ),
    );
  }
}

/// Página Pasajero: muestra "mapa" y taxis en tiempo real
class PassengerPage extends StatelessWidget {
  const PassengerPage({super.key});

  @override
  Widget build(BuildContext context) {
    final service = TaxiService();
    return StreamBuilder<List<Taxi>>(
      stream: service.taxisStream,
      builder: (context, snapshot) {
        final taxis = snapshot.data ?? service.current;
        return Padding(
          padding: const EdgeInsets.all(12),
          child: Column(
            children: [
              const Text(
                'Vista Pasajero (mapa simulado)',
                style: TextStyle(fontWeight: FontWeight.bold, fontSize: 18),
              ),
              const SizedBox(height: 12),
              // Mapa simulado
              Expanded(
                child: Container(
                  decoration: BoxDecoration(
                    border: Border.all(color: Colors.black26),
                    borderRadius: BorderRadius.circular(12),
                    color: Colors.grey[200],
                  ),
                  child: Stack(
                    children: [
                      // "Paraderos" fijos para referencia
                      Positioned.fill(
                        child: Padding(
                          padding: const EdgeInsets.all(8.0),
                          child: CustomPaint(painter: GridPainter()),
                        ),
                      ),
                      // Marcadores de taxis (usamos posición normalizada 0..1)
                      ...taxis.map((t) {
                        return Positioned(
                          left:
                              (t.position.dx) *
                              (MediaQuery.of(context).size.width - 48),
                          top:
                              (t.position.dy) *
                              (MediaQuery.of(context).size.height - 220),
                          child: TaxiMarker(
                            taxi: t,
                            onTap: () => _showTaxiDetail(context, t),
                          ),
                        );
                      }).toList(),
                    ],
                  ),
                ),
              ),
              const SizedBox(height: 12),
              // Lista rápida
              SizedBox(
                height: 120,
                child: ListView.builder(
                  scrollDirection: Axis.horizontal,
                  itemCount: taxis.length,
                  itemBuilder: (context, i) {
                    final t = taxis[i];
                    return GestureDetector(
                      onTap: () => _showTaxiDetail(context, t),
                      child: Container(
                        width: 220,
                        margin: const EdgeInsets.symmetric(horizontal: 8),
                        padding: const EdgeInsets.all(8),
                        decoration: BoxDecoration(
                          color: Colors.white,
                          border: Border.all(color: Colors.black12),
                          borderRadius: BorderRadius.circular(10),
                        ),
                        child: Column(
                          crossAxisAlignment: CrossAxisAlignment.start,
                          children: [
                            Text(
                              '${t.company} • ${t.plate}',
                              style: const TextStyle(
                                fontWeight: FontWeight.bold,
                              ),
                            ),
                            const SizedBox(height: 8),
                            Text('Asientos libres: ${t.availableSeats}'),
                            const SizedBox(height: 8),
                            Text(
                              'Estado: ${t.isActive ? "En ruta" : "Detenido"}',
                            ),
                          ],
                        ),
                      ),
                    );
                  },
                ),
              ),
            ],
          ),
        );
      },
    );
  }

  void _showTaxiDetail(BuildContext context, Taxi t) {
    showModalBottomSheet(
      context: context,
      builder: (context) {
        return Padding(
          padding: const EdgeInsets.only(
            left: 16,
            right: 16,
            top: 18,
            bottom: 18,
          ),
          child: Column(
            mainAxisSize: MainAxisSize.min,
            children: [
              Text(
                '${t.company} • ${t.plate}',
                style: const TextStyle(
                  fontWeight: FontWeight.bold,
                  fontSize: 18,
                ),
              ),
              const SizedBox(height: 8),
              Text('Asientos disponibles: ${t.availableSeats}'),
              const SizedBox(height: 8),
              Text('Estado: ${t.isActive ? "En ruta" : "Detenido"}'),
              const SizedBox(height: 12),
              ElevatedButton(
                onPressed: () {
                  // En una app real: pedir confirmación, notificar chofer, etc.
                  Navigator.pop(context);
                },
                child: const Text('Confirmar vehículo'),
              ),
            ],
          ),
        );
      },
    );
  }
}

/// Página Chofer: controla un taxi (activar, actualizar asientos, simular ruta)
class DriverPage extends StatefulWidget {
  const DriverPage({super.key});

  @override
  State<DriverPage> createState() => _DriverPageState();
}

class _DriverPageState extends State<DriverPage> {
  final TaxiService _service = TaxiService();
  String? _selectedTaxiId;

  @override
  void initState() {
    super.initState();
    final taxis = _service.current;
    if (taxis.isNotEmpty) _selectedTaxiId = taxis.first.id;
  }

  @override
  Widget build(BuildContext context) {
    return StreamBuilder<List<Taxi>>(
      stream: _service.taxisStream,
      builder: (context, snapshot) {
        final taxis = snapshot.data ?? _service.current;
        final selected = taxis.firstWhere(
          (t) => t.id == _selectedTaxiId,
          orElse: () {
            return taxis.isNotEmpty
                ? taxis.first
                : Taxi(
                    id: 'x',
                    plate: '-',
                    company: '-',
                    position: const Offset(0.5, 0.5),
                    availableSeats: 3,
                  );
          },
        );

        return Padding(
          padding: const EdgeInsets.all(12),
          child: Column(
            children: [
              const Text(
                'Vista Chofer (simulación)',
                style: TextStyle(fontWeight: FontWeight.bold, fontSize: 18),
              ),
              const SizedBox(height: 12),
              // Selector de taxi
              DropdownButton<String>(
                value: _selectedTaxiId,
                items: taxis
                    .map(
                      (t) => DropdownMenuItem(
                        value: t.id,
                        child: Text('${t.company} • ${t.plate}'),
                      ),
                    )
                    .toList(),
                onChanged: (v) => setState(() => _selectedTaxiId = v),
                isExpanded: true,
              ),
              const SizedBox(height: 12),
              // Estado y controles
              Card(
                child: Padding(
                  padding: const EdgeInsets.all(12),
                  child: Column(
                    children: [
                      Row(
                        children: [
                          const Text('Activo:'),
                          const SizedBox(width: 8),
                          Switch(
                            value: selected.isActive,
                            onChanged: (v) =>
                                _service.setActive(selected.id, v),
                          ),
                          const Spacer(),
                          Text('Asientos: ${selected.availableSeats}'),
                        ],
                      ),
                      const SizedBox(height: 8),
                      // Slider para asientos
                      Row(
                        children: [
                          Expanded(
                            child: Slider(
                              min: 0,
                              max: 6,
                              divisions: 6,
                              value: selected.availableSeats.toDouble(),
                              label: '${selected.availableSeats}',
                              onChanged: (v) {
                                _service.updateSeats(selected.id, v.toInt());
                              },
                            ),
                          ),
                        ],
                      ),
                      const SizedBox(height: 8),
                      Row(
                        children: [
                          ElevatedButton.icon(
                            icon: const Icon(Icons.play_arrow),
                            label: const Text('Simular ruta corta'),
                            onPressed: () {
                              final route = _generateRouteAround(
                                selected.position,
                              );
                              _service.simulateRoute(selected.id, route);
                            },
                          ),
                          const SizedBox(width: 8),
                          OutlinedButton.icon(
                            icon: const Icon(Icons.location_off),
                            label: const Text('Detener'),
                            onPressed: () =>
                                _service.setActive(selected.id, false),
                          ),
                        ],
                      ),
                    ],
                  ),
                ),
              ),
              const SizedBox(height: 12),
              Expanded(
                child: ListView.builder(
                  itemCount: taxis.length,
                  itemBuilder: (context, i) {
                    final t = taxis[i];
                    return ListTile(
                      title: Text('${t.company} • ${t.plate}'),
                      subtitle: Text(
                        'Asientos: ${t.availableSeats} • Estado: ${t.isActive ? "En ruta" : "Detenido"}',
                      ),
                      trailing: IconButton(
                        icon: const Icon(Icons.edit),
                        onPressed: () {
                          // Seleccionar taxi para editar
                          setState(() => _selectedTaxiId = t.id);
                        },
                      ),
                    );
                  },
                ),
              ),
            ],
          ),
        );
      },
    );
  }

  // Genera una ruta simple (puntos cercanos)
  List<Offset> _generateRouteAround(Offset origin) {
    final rand = Random();
    final points = <Offset>[];
    for (var i = 0; i < 8; i++) {
      final dx = ((rand.nextDouble() - 0.5) * 0.15);
      final dy = ((rand.nextDouble() - 0.5) * 0.15);
      points.add(
        Offset(
          (origin.dx + dx).clamp(0.02, 0.98),
          (origin.dy + dy).clamp(0.02, 0.98),
        ),
      );
    }
    return points;
  }
}

/// Widget visual del marcador de taxi
class TaxiMarker extends StatelessWidget {
  const TaxiMarker({super.key, required this.taxi, this.onTap});

  final Taxi taxi;
  final VoidCallback? onTap;

  @override
  Widget build(BuildContext context) {
    final color = taxi.availableSeats > 0 ? Colors.green : Colors.red;
    return GestureDetector(
      onTap: onTap,
      child: Column(
        children: [
          Container(
            padding: const EdgeInsets.symmetric(horizontal: 6, vertical: 4),
            decoration: BoxDecoration(
              color: Colors.white,
              borderRadius: BorderRadius.circular(6),
              boxShadow: const [
                BoxShadow(blurRadius: 4, color: Colors.black12),
              ],
            ),
            child: Row(
              children: [
                Icon(Icons.directions_car, size: 16, color: color),
                const SizedBox(width: 6),
                Text(
                  '${taxi.company} (${taxi.availableSeats})',
                  style: const TextStyle(fontSize: 12),
                ),
              ],
            ),
          ),
          const SizedBox(height: 4),
          // "Punta" del marcador
          Icon(Icons.location_pin, size: 20, color: color),
        ],
      ),
    );
  }
}

/// Pintor de fondo del "mapa" para referencia (grid)
class GridPainter extends CustomPainter {
  @override
  void paint(Canvas canvas, Size size) {
    final paint = Paint()..color = Colors.black12;
    const step = 40.0;
    for (double x = 0; x < size.width; x += step) {
      canvas.drawLine(Offset(x, 0), Offset(x, size.height), paint);
    }
    for (double y = 0; y < size.height; y += step) {
      canvas.drawLine(Offset(0, y), Offset(size.width, y), paint);
    }
  }

  @override
  bool shouldRepaint(covariant CustomPainter oldDelegate) => false;
}
