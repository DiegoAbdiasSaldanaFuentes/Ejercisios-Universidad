//  Opcion 1
function cualEsmayor(a,b){
    if (a > b){
        return a;
    } else{
        return b
    }
}
let mayor = cualEsmayor(10,5);
console.log(mayor)

// Opcion 2
function cualEsmayor1(a,b){
    return (a > b) ? a:b;
}
let mayor1 = cualEsmayor1(10,5);
console.log(mayor1)