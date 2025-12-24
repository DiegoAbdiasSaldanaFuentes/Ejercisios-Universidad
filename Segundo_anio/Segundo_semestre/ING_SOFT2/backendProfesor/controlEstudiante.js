/*
EJERCICIO 1.
1. Se solicitar crear UNA ESTRUCTURA para almacena todos los errores que pueden ocurrir en la ejecucion de un Servidor. 
La estructura puede estar compuesta. A modo de ejemplo, abajo hay 5 ejemplos. Su estructura debe permitir agregar
mas mensajes de errores y debe continuar funcionando bien. Es considerada incorrecta la respuesta que usada if o Switch para diferenciar cada uno de los tipos de mensajes ya que la tabla de abajo tiene 100 mensajes de getSystemErrorMessage.   

Nombre del error            estado         tipo        mensaje
ER_ACCESS_DENIED_ERROR        401          fail        Credenciales de base de datos inválida
ER_BAD_DB_ERROR               500          error        La base de datos solicitada no existe
ER_CON_COUNT_ERROR            503          error        Demasiadas conexiones activas a la base de datos
PROTOCOL_CONNECTION_LOST      503          error        Conexión con la base de datos perdida
ECONNREFUSED                  503          error        La base de datos no responde (servidor apagado o inaccesible)
 
imprima dos ejemplos por consola de errores aplicando su estructura.
*/


//EJERCICIO 2.
/*
elabore un programa imprima el nombre y el departamento de la personas cuyo sueldo este entre 500000 y 800000. Para todos los efectos, su solucion 
debe funcionar correcatmente si cambio un sueldo de las personas

*/
//Los array  de funcionarios tiene valores relacionados con codigo del funcionario, sueldo y codigo de partemento al que pertenece

// Imprimir nombre y departamento de personas cuyo sueldo esté entre 500000 y 800000

let funcionarios = [
  [  1,  197000, 1],
  [ 2,   860000, 2 ],
  [ 3,   700000,  4  ],
  [ 4,   1800000,  1  ],
  [ 5,   1500000,  4  ],
  [ 6,   2500000,  5  ],
  [ 7,   1000000,  1  ],
  [ 8,   2800000,  3  ],
  [ 9,   500000,  2  ],
  [ 10,  777000,  1  ],
  [ 11,  1500000,  2  ],
  [ 12,  800000,  4  ]
];

let departamento = ["ICI", "EICI", "ICE", "TRE", "OTE"];
let nombres = ["Ana", "Alexa", "Clau", "Luis", "Paul", "Fori", "Lou", "Chang", "Kart", "Mei", "Rosa", "Jana"];

/*
Nombre: Clau, Departamento: TRE, Sueldo: 700000
Nombre: Kart, Departamento: EICI, Sueldo: 500000
Nombre: Mei, Departamento: ICI, Sueldo: 777000
Nombre: Jana, Departamento: TRE, Sueldo: 800000
*/



//EJERCICIO 3 ESCRIBA UN PROGRAMA QUE DIBUJE UN GRAFICO DE BARRA VERTICAL
let pais = ["Chile","Peru","Argentina" ]
let habitantes = [ 3, 6, 12]
/* 
                          ************ 
                          ************ 
                          ************ 
                          ************ 
             ************ ************ 
             ************ ************ 
             ************ ************ 
************ ************ ************ 
************ ************ ************ 
************ ************ ************ 
   Chile      Peru         Argentina
*/