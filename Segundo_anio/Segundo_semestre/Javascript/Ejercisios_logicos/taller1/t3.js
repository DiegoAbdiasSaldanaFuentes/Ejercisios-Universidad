/* *************************************************************************************************************************************************************************************
3.	Usa diccionarios de Javascript para almacenar las instancias de las siguientes entidades:
•	Patologo: tiene los atributos IdPatologo (valor entero secuencial), nombreCompleto (cualquier string),  codigoEspecialidad (codigo de 1 a 10), activo (0 o 1), sexo (F o M).
•	Biopsia tiene los siguientes atributos: IdBiopsia, nombre, tiempoDuracion (1 a 180 minutos),
•	Asignacion de biopsia tiene los datos: idAsignacion(numero entero secuencial), idBiopsia, idPatologo, descripción (cualquier string) 
Consideraciones
a.	hay 10 patólogos
b.	La carga inicial de trabajo. Puede ser todos con cero minutos o bien carga inicial de diferentes minutos que están entre 30 y 180
c.	Funciones
d.	listar las asignaciones
e.	lista el total de minutos que tiene cada patólogo
 ***************************************************************************************************************************************************************************************/

//Diccionario Patologo
const patologo = {}
    for(let i = 1; i <=10; i++){
        let num=Math.round(Math.random());
        let genero = (1== num) ? "M" : "F";

        patologo[i] = {
            idPatologo : i,
            nombreCompleto : "NombrePatologo"+i,
            codigoEspecialidad : i,
            activo : num,
            sexo : genero
        };
    };


//Diccionario Biopsia
const biopsia = {}
    for(let i = 1; i <=10; i++){
        let num=1+Math.round(Math.random()*179);

        biopsia[i] = {
            idBiopsia : i,
            nombre : "Biopsia" + i,
            tiempoDuracion : num,
        };
    };


//Mostrar Patologo
for(let clave in patologo){
    console.log(clave, ":", patologo[clave]);
}

console.log("\n");

//Mostrar Biopsia
for(let clave in biopsia){
    console.log(clave, ":", biopsia[clave]);
}
