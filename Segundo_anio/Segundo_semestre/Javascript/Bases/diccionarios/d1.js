//Uso basico


const diccionario = {//Definir
    nombre : "Diego",
    edad : 19
};

for( clave in diccionario){//Imprimir
    console.log(clave, ":", diccionario[clave]);
};

/*****************************************************************************************************************
 * Recuerda Diego que esta forma de llamar al diccionario es más dinamica que hacer diccionario.nombre, si hay 
 * caracteres especiales no funciona, recomendable usar esta manera
 * 
******************************************************************************************************************/