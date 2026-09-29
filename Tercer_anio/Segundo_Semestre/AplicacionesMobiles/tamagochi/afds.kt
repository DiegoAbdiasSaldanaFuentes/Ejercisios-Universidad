/**
 * Author: Diego Abdías Saldaña Fuentes
 * Fecha: 11 de Septiembre, 2026
 * Nombre de la Aplicación: Simulador de Mascota Virtual
 */

data class EstadoMascota(
    var energia: Int = 100,
    var felicidad: Int = 100,
    var sed: Int = 0,
    var hambre: Int = 0,
    var salud: Int = 100,
    var tiempoTotalMinutos: Int = 0
)

fun main() {
    val mascota = EstadoMascota()
    var mascotaDespierta = true

    // Constantes de las opciones del menú
    val OPCION_ALIMENTAR = 1
    val OPCION_JUGAR = 2
    val OPCION_PASEAR = 3
    val OPCION_REVISAR = 4
    val OPCION_SALIR = 5

    println("¡Bienvenido al simulador de mascota virtual!")

    while (mascotaDespierta) {
        println("\n¿Qué quieres hacer?")
        print("[1] Alimentar [2] Jugar [3] Pasear [4] Revisar estado [5] Salir: ")

        val accion = readlnOrNull()?.toIntOrNull()

        when (accion) {
            OPCION_ALIMENTAR -> alimentar(mascota)
            OPCION_JUGAR -> jugar(mascota)
            OPCION_PASEAR -> pasear(mascota)
            OPCION_REVISAR -> revisarEstado(mascota)
            OPCION_SALIR -> {
                println("Saliendo de la simulación...")
                mascotaDespierta = false
            }
            else -> println("Acción no válida.")
        }

        if (mascotaDespierta && accion in OPCION_ALIMENTAR..OPCION_PASEAR) {
            mascotaDespierta = verificarReglasDeEstado(mascota)
        }
    }
}

fun alimentar(m: EstadoMascota) {
    m.energia += 20
    m.hambre = (m.hambre - 40).coerceAtLeast(0)
    m.tiempoTotalMinutos += 10
    println("¡Has alimentado a tu mascota! Energía +20, Hambre -40. (Tiempo: +10 min)")
}

fun jugar(m: EstadoMascota) {
    m.energia -= 15
    m.felicidad += 25
    m.sed += 30
    m.hambre += 15
    m.tiempoTotalMinutos += 15
    println("¡Jugaste con tu mascota! Energía -15, Felicidad +25, Sed +30. (Tiempo: +15 min)")
}

fun pasear(m: EstadoMascota) {
    m.energia -= 60
    m.felicidad += 25
    m.sed += 20
    m.hambre += 20
    m.tiempoTotalMinutos += 60
    println("¡Paseaste a tu mascota! Energía -60, Felicidad +25, Sed +20. (Tiempo: +1 hora)")
}

fun revisarEstado(m: EstadoMascota) {
    println("Estado actual: Energía=${m.energia}, Felicidad=${m.felicidad}, Hambre=${m.hambre}, Sed=${m.sed}, Salud=${m.salud}, Tiempo Jugado=${m.tiempoTotalMinutos} min.")
}

fun verificarReglasDeEstado(m: EstadoMascota): Boolean {
    // Constantes de reglas de negocio
    val LIMITE_HAMBRE_CRITICO = 90
    val LIMITE_FELICIDAD_MINIMA = 0
    val LIMITE_SED_MORTAL = 100
    val LIMITE_ENERGIA_MINIMA = 0
    val LIMITE_SALUD_MINIMA = 0

    val PENALIZACION_SALUD_HAMBRE = 35
    val PENALIZACION_FELICIDAD_HAMBRE = 60
    val PENALIZACION_ENERGIA_TRISTEZA = 50

    if (m.hambre >= LIMITE_HAMBRE_CRITICO) {
        println("¡Advertencia! La mascota está desnutrida. Salud -$PENALIZACION_SALUD_HAMBRE, Felicidad -$PENALIZACION_FELICIDAD_HAMBRE.")
        m.salud -= PENALIZACION_SALUD_HAMBRE
        m.felicidad -= PENALIZACION_FELICIDAD_HAMBRE
    }

    if (m.felicidad <= LIMITE_FELICIDAD_MINIMA) {
        println("¡Advertencia! La mascota está muy deprimida. Energía -$PENALIZACION_ENERGIA_TRISTEZA.")
        m.energia -= PENALIZACION_ENERGIA_TRISTEZA
    }

    if (m.sed >= LIMITE_SED_MORTAL) {
        println("Tu mascota ha muerto deshidratada... RIP.")
        return false
    }

    if (m.energia <= LIMITE_ENERGIA_MINIMA) {
        println("Tu mascota está demasiado cansada. ¡Se durmió! Zzzzzz...")
        return false
    }

    if (m.salud <= LIMITE_SALUD_MINIMA) {
        println("La salud de tu mascota llegó a 0. Fin de la simulación.")
        return false
    }

    return true
}