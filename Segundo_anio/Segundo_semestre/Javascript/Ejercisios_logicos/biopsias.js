
let patologos = {};

for(let i = 1; i<=10; i++){
    patologos[i]={
        id:i,
        nombre: `DR.HOUSE ${i}`,
        minutosTotales: 0
    }
}

for(let j=1; j<=20; j++){

    let duracion_biopsia = 1+Math.floor(Math.random()*180);
    let idPatologo = 1+Math.floor(Math.random()*10);
 

    if(patologos[idPatologo]){
        patologos[idPatologo].minutosTotales += duracion_biopsia;
        let nombreA = patologos[idPatologo].nombre;
        console.log(`Biosia N°${j} de ${duracion_biopsia} minutos asinganda al Patologo ${nombreA}`)
    }
}

console.log("\n====================================");

for(let id in patologos){
    let pat =patologos[id]
    console.log(`El Patologo ${pat.nombre} tiene una carga total de ${pat.minutosTotales} minutos`)
}