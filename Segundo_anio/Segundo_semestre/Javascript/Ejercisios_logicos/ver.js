/*Objetivo: usar startsWith(), toUpperCase(), if
Consigna:
Solicita un nombre (por ejemplo "Diego") y determina si empieza con una vocal o consonante.
Si empieza con vocal, muestra "Nombre inicia con vocal".
Si empieza con consonante, muestra "Nombre inicia con consonante".
Herramientas sugeridas:
nombre.toUpperCase()
startsWith("A"), startsWith("E")…
if / else */

let nombre = "Diego";
let primera = nombre.charAt(0).toUpperCase();

if("AEIOU".includes(primera)){
    console.log(nombre,"empieza con una vocal");
}else{
    console.log("Empieza con una consonante");
};
