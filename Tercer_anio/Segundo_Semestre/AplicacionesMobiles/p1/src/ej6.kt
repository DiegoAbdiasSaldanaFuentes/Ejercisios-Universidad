// Función para calcular el subtotal de un solo producto
fun calcularSubtotal(precio: Double, cantidad: Int): Double {
    return precio * cantidad
}

// Función para calcular el impuesto (Ej: IVA 19%)
fun aplicarImpuesto(subtotal: Double, porcentajeImpuesto: Double): Double {
    return subtotal + (subtotal * porcentajeImpuesto / 100)
}

// Función para calcular el vuelto
fun calcularVuelto(total: Double, montoPagado: Double): Double {
    return montoPagado - total
}

fun main() {
    // 1. Declaración de variables usando val (no van a cambiar de valor durante la ejecución)
    val nombreProducto = "Arroz 1kg"
    val precioProducto = 1200.0
    val cantidadLlevada = 3

    // 2. Procesamiento de datos llamando a las funciones
    val subtotal = calcularSubtotal(precioProducto, cantidadLlevada)
    val totalConImpuesto = aplicarImpuesto(subtotal, 19.0)

    // 3. Salida por consola usando String Templates
    println("--- TICKET DE SUPERMERCADO ---")
    println("Producto: $nombreProducto")
    println("Cantidad: $cantidadLlevada")
    println("Subtotal: $$subtotal")
    println("Total a pagar (con IVA): $$totalConImpuesto")
    println("------------------------------")

    // 4. Lógica de pago
    val montoEntregado = 5000.0
    println("Monto entregado: $$montoEntregado")

    if (montoEntregado >= totalConImpuesto) {
        val vuelto = calcularVuelto(totalConImpuesto, montoEntregado)
        println("Vuelto a entregar: $$vuelto")
    } else {
        val faltante = totalConImpuesto - montoEntregado
        println("Error: Falta dinero. El cliente debe $$faltante más.")
    }
}