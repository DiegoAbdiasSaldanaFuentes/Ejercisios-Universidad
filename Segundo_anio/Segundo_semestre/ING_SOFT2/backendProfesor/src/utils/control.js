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


 let funcionarios = [
  { codigo: 1, sueldoBruto: 9700000, depto:1 },
  { codigo: 2, sueldoBruto: 1600000, depto:2 },
  { codigo: 3, sueldoBruto: 700000, depto:4 },
  { codigo: 4, sueldoBruto: 1800000, depto:1 },
  { codigo: 5, sueldoBruto: 1500000, depto:4 },
  { codigo: 6, sueldoBruto: 1880000, depto:5 },
  { codigo: 7, sueldoBruto: 1000000, depto:1 },
  { codigo: 8, sueldoBruto: 2800000, depto:3 },
  { codigo: 9, sueldoBruto: 500000, depto:2 },
  { codigo: 10, sueldoBruto: 777000, depto:1 },
  { codigo: 11, sueldoBruto: 1500000, depto:2 },
  { codigo: 12, sueldoBruto: 800000, depto:4 }
];

let departamento = ["ICI", "EICI", "ICE", "TRE", "OTE"];
let nombres = ["Ana", "Alexa", "Clau", "Luis", "Paul", "Fori", "Lou", "Chang", "Kart", "Mei", "Rosa", "Jana"];

// 1️⃣ Encontrar el sueldo mínimo
let sueldoMinimo = Math.min(...funcionarios.map(f => f.sueldoBruto));

// 2️⃣ Filtrar todas las personas con ese sueldo
let personasMenorSueldo = funcionarios.filter(f => f.sueldoBruto === sueldoMinimo);

// 3️⃣ Imprimir nombre + departamento
personasMenorSueldo.forEach(p => {
  let nombre = nombres[p.codigo - 1];          // arreglo comienza en 0
  let deptoNombre = departamento[p.depto - 1]; // arreglo comienza en 0
  
  console.log(`Nombre: ${nombre}, Departamento: ${deptoNombre}, Sueldo: ${p.sueldoBruto}`);
});

