
let caracterBarra= "|";


for(let i=1; i<=5;i++){
    let visitas = 500+Math.round(Math.random()*500)
    let cantidadBarras =Math.floor(visitas/10)
    let resultado = caracterBarra.repeat(cantidadBarras);
    let nombreServidor = `Srv-${i}`.padEnd(6, " ");
    console.log(nombreServidor,resultado,visitas);
}