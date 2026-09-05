
fun main(){
    val edad = 20


    if (edad >= 18){
        println("Es mayor de edad")
    }else{
        println("No es mayor de edad fuera de aqui")
    }

    val mensaje = if(edad>=18)"acceso concedido" else "Acceso denegado"
    println(mensaje)
}