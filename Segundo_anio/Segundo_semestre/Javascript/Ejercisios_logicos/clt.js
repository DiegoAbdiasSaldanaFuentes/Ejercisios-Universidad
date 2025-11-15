/**Objetivo: combinar random, operadores ternarios y lógica encadenada.
Consigna:
Genera una temperatura aleatoria entre 0 y 40 grados.
Mayor a 30 → "Caluroso"
Entre 15 y 30 → "Agradable"
Menor a 15 → "Frío"
Herramientas:
Math.random(), Math.floor()
operador ternario anidado ? : */

let temperatura = Math.floor(Math.random()*41)

let estado = (temperatura > 30) ? "Caluroso": (temperatura >=15) ? "Agradable" : "Frio";
console.log(`Temperatura: ${temperatura} \nEstado : ${estado}`);