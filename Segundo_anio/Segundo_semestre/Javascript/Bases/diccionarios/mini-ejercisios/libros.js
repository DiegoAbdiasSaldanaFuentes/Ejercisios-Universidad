/**
Ejercicio 1
Crea un objeto llamado libro con las claves:
titulo
autor
anio
Luego:
Imprime cada valor.
Modifica el año.
Agrega una nueva clave disponible con valor true.
 */

const libro = {
    autor : "Diego",
    anio : 2006
};

for(clave in libro){
    console.log(clave, ":" ,libro[clave]);
};

console.log("\n");

libro.anio = 2025;
libro.disponible = true;

for(clave in libro){
    console.log(clave, ":" ,libro[clave]);
};