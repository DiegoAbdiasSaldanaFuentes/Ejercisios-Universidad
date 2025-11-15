/*Objetivo: practicar switch con strings.
Consigna:
Recibe un nombre de ciudad ("Talca", "Santiago", "Chillán", "Antofagasta") y muestra el nombre de la región a la que pertenece.
Si la ciudad no está registrada, muestra "Ciudad no encontrada".

Herramientas:

switch

default */

let ciudad = "Talca";
let region;

switch(ciudad){
    case "Santiago":
        region = "Región Metropolitana";
        break;
    case "Talca":
        region = "Región del Maule";
        break;
    case "Chillán":
        region = "Región de Ñuble";
        break;
    case "Antofagasta":
        region = "Región de Antofagasta";
        break;
    default:
        region = "Ciudad no encontrada";
};

console.log(`${ciudad} pertenece a la ${region}`);