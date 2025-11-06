// Funcion más flexible
// La función recibe un parametro 
function suma(a,b){
    // metodo para ver los valores que estan almacenado en suma
    console.log(arguments);
    return a + b;
}
// Le pasamos a la funcion un argumento
let resultado = suma(5,6,1,2,3);

console.log(resultado);
console.log(typeof suma);


