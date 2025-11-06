/**
 * Crear algoritmo que devuelve
 * el precio del producto 
 * más impuesto
 */

function preciocompleto(precio, impuesto){
    return(precio + precio * impuesto)
}

let resultado = preciocompleto(19.90,0.15);
console.log(resultado)