// Los tipados estaticos son aquellos que no pueden cambiar su valor osea no pueden pasar de str a int
// debido a que eso causaria errores
// sin embargo el tipado dinamico si nos permite realizar ese cambio

let numero = 42;
let nombre = 'hola mundo';
let verdadero = true;
let undef;
let nula = null;
// Aqui tenemos un ejemplo del tipado dinamico
nombre = 53;
// typeof nos permite ver el tipo de dato como el type de python
console.log(typeof nombre);