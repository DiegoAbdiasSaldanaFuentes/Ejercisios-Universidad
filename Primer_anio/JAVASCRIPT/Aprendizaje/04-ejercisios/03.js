/**
 * indice validar que no sea menor a cero y que el elemento exista en el array
 * 
 */
function getbyidx(arr,idx){
    if (idx < 0 || arr.length <= idx){
        return 'elemento no existe';
    }
    return arr[idx]
}
let resultado = getbyidx([1,2],0)
console.log(resultado);