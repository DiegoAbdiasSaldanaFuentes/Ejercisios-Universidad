const poblaciones = [5, 7, 9]; // Ejemplo
const maxAltura = Math.max(...poblaciones);

for (let fila = maxAltura; fila > 0; fila--) { // desde la cima hacia abajo
    let linea = "";
    for (let col = 0; col < poblaciones.length; col++) {
        if (poblaciones[col] >= fila) {
            linea += " * ";
        } else {
            linea += "   ";
        }
    }
    console.log(linea);
}

// Etiquetas al final (puedes adaptarlas)
console.log(" BOL CHI ARG");
