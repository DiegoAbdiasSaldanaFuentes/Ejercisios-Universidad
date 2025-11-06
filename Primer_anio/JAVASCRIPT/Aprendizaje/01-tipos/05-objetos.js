//personaje de TV

let nombre = 'Tanjiro'
let anime = 'Demon slayer'
let edad = 16
// creando un objeto par llave-valor
let personaje = {
    nombre: 'Tanjiro',
    anime: 'Demon slayer',
    edad: 16
};
// llamando a toda la propiedad
console.log(personaje);
// llamando a una sola propiedad
console.log(personaje.nombre);
// otra manera de llamar a una sola
console.log(personaje['anime']);
// Modificando la propiedad
personaje.edad = 13;
// otra manera de modificar la edad
personaje['edad'] = 16;
// Eliminando propiedad
delete personaje.anime;
console.log(personaje)