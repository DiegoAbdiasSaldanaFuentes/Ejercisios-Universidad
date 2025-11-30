//CREAR UN DICCIONARIO VACIO

let boveda = {};
console.log(boveda);

//INICIALIZACION DE INFORMACIÓN
for(let i=1; i<=5; i++){
    boveda[i]={
        id:i,
        muebles: 0,
        articulos_navidenios: 0,
        articulos_hallowin: 0,
        basura: 0
    };
}

//INSERTAR DATOS
for(let i=1; i<=10; i++){

    let idAleatorio = 1+Math.floor(Math.random()*5);
    let cantidadMuebles = 1+Math.floor(Math.random()*99);
    let cantidadAN = 1+Math.floor(Math.random()*99);
    let cantidadAH = 1+Math.floor(Math.random()*99);
    let cantidadBasura = 1+Math.floor(Math.random()*99);

    //VERIFICACION DE QUE EXISTA
    if(boveda[idAleatorio]){
        boveda[idAleatorio].muebles += cantidadMuebles;
        boveda[idAleatorio].articulos_navidenios += cantidadAN;
        boveda[idAleatorio].articulos_hallowin += cantidadAH;
        boveda[idAleatorio].basura += cantidadBasura;

        
        console.log(`\nBOVEDA ${idAleatorio} \n \n Muebles ${cantidadMuebles}\n Articulos Navidenios ${cantidadAN} \n Articulos Hallowen ${cantidadAH} \n Cantidad Basura ${cantidadBasura}`);
        console.log(`Evento ${i}: Se descargo material en la boveda ${idAleatorio}`)
    }
}
