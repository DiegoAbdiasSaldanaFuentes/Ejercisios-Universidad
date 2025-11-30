/**
 * ESTE EJEMPLO ES DE UNA IA
 */

console.clear();
console.log("=== SISTEMA DE GESTIÓN DE CARGA MINERA ===");

// 1. CREACIÓN DEL DICCIONARIO (LA FLOTA)
// Usamos un objeto vacío. Aquí guardaremos los camiones por su ID.
const camiones = {}; 

// Inicializamos 10 camiones
for (let i = 1; i <= 10; i++) {
    // La CLAVE (Key) es el número del camión (1, 2, 3...)
    // El VALOR es otro objeto con sus datos.
    camiones[i] = {
        id: i,
        patente: `CP-${i + 100}`, // Genera patentes tipo CP-101, CP-102...
        cargaActual: 0,           // ¡IMPORTANTE! Inicializar en 0
        viajes: 0                 // Un contador extra para saber cuántas rocas llevó
    };
}

// 2. SIMULACIÓN DE TRABAJO (LAS ROCAS)
console.log("\n--- Iniciando Carga de Rocas ---");

// Simulamos 20 rocas
for (let r = 1; r <= 20; r++) {
    // Generar datos aleatorios de la roca
    let pesoRoca = Math.floor(Math.random() * (500 - 100 + 1)) + 100; // Entre 100 y 500
    
    // Elegir un camión al azar (del 1 al 10)
    let idCamionElegido = Math.floor(Math.random() * 10) + 1;

    // --- AQUÍ ESTÁ LA MAGIA (ACCESO DIRECTO) ---
    // No recorremos un array buscando el camión. Vamos directo a él usando su ID.
    // Verificamos que exista (buena práctica)
    if (camiones[idCamionElegido]) {
        // Acumulamos el peso
        camiones[idCamionElegido].cargaActual += pesoRoca; 
        camiones[idCamionElegido].viajes++;
        
        console.log(`Roca ${r} (${pesoRoca}kg) -> Cargada en Camión ${idCamionElegido}`);
    }
}

// 3. REPORTE FINAL
console.log("\n=== REPORTE FINAL DE FLOTA ===");

// Recorremos el diccionario para mostrar resultados.
// "for...in" es el bucle especial para recorrer las CLAVES de un objeto.
for (let id in camiones) {
    let camion = camiones[id]; // Recuperamos el objeto completo del camión
    console.log(`Camión ${camion.id} [${camion.patente}] | Carga Total: ${camion.cargaActual} kg | Rocas: ${camion.viajes}`);
}