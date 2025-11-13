/*********************************************************
 * Uso de funciones que convierta las propiedades en arrays
 **********************************************************/


const persona = { 
    nombre: "Diego",
    edad: 19,
    profesion: "Estudiante" };

for (let clave in persona) {
    console.log(clave, ":", persona[clave]);
}



console.log(Object.keys(persona));   // ["nombre", "edad", "profesion"]
console.log(Object.values(persona)); // ["Diego", 19, "Estudiante"]
console.log(Object.entries(persona));// [["nombre", "Diego"], ["edad", 19], ...]
