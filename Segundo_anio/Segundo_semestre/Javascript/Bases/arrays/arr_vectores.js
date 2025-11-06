let numeros = [10, 20, 30, 40];

console.log(numeros[0]); // acceder al primero
numeros.push(50); // agregar al final
numeros.pop(); // eliminar último elemento
console.log(numeros.length); // cantidad de elementos

// recorrer
for (let i = 0; i < numeros.length; i++) {
    console.log(numeros[i]);
}
