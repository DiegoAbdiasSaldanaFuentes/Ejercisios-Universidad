// Solo funciona en Node.js
const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question("Ingrese su nombre: ", function(nombre) {
    console.log("Hola, " + nombre);
    rl.close();
});
