/**
 * Los diccionarios no existen como tal solo los disimulamos
 */


// A. DICCIONARIO DE JUGADORES (La entidad principal)
// Usamos el ID como clave para acceder rápido.
const jugadores = {
    1: { id: 1, nombre: "Faker", totalPuntos: 0 },
    2: { id: 2, nombre: "Chovy", totalPuntos: 0 }
};

// B. DATOS DE PARTIDAS (Las tareas/eventos)
// Fíjate que cada partida tiene un "idJugador" que lo conecta con el diccionario de arriba.
const partidas = [
    { idPartida: 101, puntos: 15, idJugador: 1 }, // Faker jugó esta
    { idPartida: 102, puntos: 20, idJugador: 2 }, // Chovy jugó esta
    { idPartida: 103, puntos: 10, idJugador: 1 }  // Faker jugó esta también
];

// C. PROCESO DE ASIGNACIÓN (Sumar puntos)
// Recorremos las partidas (el trabajo) y actualizamos al jugador (el trabajador)
for (let i = 0; i < partidas.length; i++) {
    let partidaActual = partidas[i];
    let idDelDueño = partidaActual.idJugador; // Sacamos el ID: 1 o 2
    let puntosGanados = partidaActual.puntos;

    // MAGIA DE DICCIONARIOS:
    // Accedemos directamente al jugador usando su ID sin buscar en un array
    if (jugadores[idDelDueño]) { 
        jugadores[idDelDueño].totalPuntos += puntosGanados;
    }
}

console.log(jugadores[1]); // Muestra a Faker con 25 puntos (15+10)