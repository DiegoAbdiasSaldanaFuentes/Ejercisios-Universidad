/**
 * crear  algoritmo que tome un array
 * de ojetos y  devuelva  un array
 * pares
 */
let array =[{
    id:1,
    name:'nicolas',
},{
    id:2,
    name:'Felipe'

},{
    id: 3,
    name:'chanchito',

}];

let pares =[
    [1,{id:1,name:'nicolas'}],
    [2,{id:2,name:'felipe'}],
    [3,{id:3,name:'chanchito'}],
];

    
function topairs(arr){
    let pairs = [];
    for (idx in arr){
        let elemento= arr[idx];
        pairs[idx]  = [elemento.id,elemento];

    }
    return pairs
}

let resultado = topairs(array);