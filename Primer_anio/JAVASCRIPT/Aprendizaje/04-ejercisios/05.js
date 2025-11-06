/**
 * Crear agoritmo que devuelva número
 * menor y mayor de un array
 */

let array = [2,5,7,15,-5,-100,55];

function getmenormayor(arr){
    let menor =arr[0];
    let mayor = arr[0];
    for (numero of arr){
        menor = menor < numero ? menor : numero;
        mayor = mayor > numero ? mayor : numero;
    }
    return [menor,mayor];
}

let numero = getmenormayor(array);
console.log(numero);