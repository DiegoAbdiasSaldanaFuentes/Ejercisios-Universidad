/**
 * Crear un algoritmo que devuelva 
 * cantidad de número positivos de un array
 */
let array = [2,5,7,15,-5,-100,55];

function cuantospositivos(arr){
    let cantidad = 0;
    for (elem of arr){
        if (elem > 0){
            cantidad++;
        }
    }
    return cantidad
}

let resultado = cuantospositivos(array);
console.log(resultado);