let miNota = 2+Math.round(Math.random()*7);
console.log(miNota);
switch (true) {
    case miNota >= 6 && miNota <=7:
        console.log("Excelente");
        break;

    case (miNota >= 4 && miNota <=5):
        console.log("Bien");
        break;
    case (miNota >= 2 && miNota <=3):
        console.log("Mal");
        break;
    default:
        console.log("Puntaje fuera de rango");
        break;
}