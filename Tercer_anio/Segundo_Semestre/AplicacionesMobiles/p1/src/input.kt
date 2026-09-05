fun main(){
    print("ingresa tu nombre")
    val nombre = readln()

    print("Ingrese tu edad")
    val edad = readln().toIntOrNull() ?:0
    println("Hola, $nombre, el próximo año tendrás ${edad + 1} años.")
}