// DefiniciÃ³n de  tipos de variables en Javascript

/*
Carrera de IngenierÃ­a InformÃ¡tica 
Curso de IngenierÃ­a de software II
*/


// = == = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =  
//1. Tipo string (cadenas de texto)
//Representa texto. Puede declararse con comillas simples ' ', dobles " ", o template literals ` ` (plantillas con interpolaciÃ³n).
//Valores enteros
console.log("Ejemplos de tipos de datos en javascript")
console.log("=".repeat(50))
cantidadHermano=100
temperaturaTalca=21.6
let estaAprobado = true
let estaReprobado = false
console.log("Tota= ",cantidadHermano, " Temperatura= ",temperaturaTalca, " estaAprobado=")

let nombre = "MARGARITA";
let mensaje = `Bienvenida ${nombre}!`;

 
// MÃ©todos comunes: .toUpperCase(), .toLowerCase()
console.log("=============== Aplicando  toUpperCase() y toLowerCase()=========================");    
console.log("original= ",nombre, "                     todo en mayÃºscula= ",nombre.toUpperCase());  
console.log("original= ",mensaje, "         todo en minÃºscula= ",mensaje.toLowerCase()); 
console.log("\n\n") 





// = == = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = 
console.clear()
// MÃ©todos comunes:  .includes()
//La bÃºsqueda con includes() distingue entre mayÃºsculas y minÃºsculas
console.log("\n\n\n=============== MÃ©todo includes =========================")
let mensajeSeptiembre="el 18 de septiembre fue disfrutado por todos los chilenos a lo largo de Chile"
console.log("Texto original: ", mensajeSeptiembre)
console.log("1. buscando 18 desde la posiciÃ³n 0 ", mensajeSeptiembre.includes("18", 0));  
console.log("2. buscando 18 desde la posiciÃ³n 5 ", mensajeSeptiembre.includes("18", 7));   
console.log("\n\n")







// = == = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = 
console.clear()
//La bÃºsqueda con .replace() distingue entre mayÃºsculas y minÃºsculas
//solo reemplaza SOLAMENTE la primera coincidencia del substring.
console.log("\n\n\n=============== MÃ©todo .replace() y replaceAll()  =========================")
let mensajeMayo="el 21 de mayo fue disfrutado por todos los chilenos a lo largo de las costas de Chile: Viva el 21"
console.log(mensajeMayo)
console.log("1. reemplazo 21 por 25:   ", mensajeMayo.replace("21", "25"));   
console.log("2. reemplazo TODOS LOS 21 por 25:   ", mensajeMayo.replaceAll("21", "25"));   
console.log("3. Elimina los  espacios en blanco por vacio:     ", mensajeMayo.replaceAll(" ",""));   
console.log("\n\n")





// = == = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = 
console.clear()
//  retorna un array de los elementos de texto, usando el separador llamado criterio
console.log("\n\n\n=============== MÃ©todo  texto.split(criterio)   =========================")
let mensajeJunio="el 7 de junio fue disfrutado por todos"
console.log(mensajeJunio)
console.log("1. separar usando un espacio vacio   ", mensajeJunio.split(" "));   
mensajeJunio="el_7_de_junio_fue_disfrutado por todos"
console.log("2. separar usando _   ", mensajeJunio.split("_"));   
console.log("3. separar usando _ pero el resultado tiene 3 elementos   ", mensajeJunio.split("_", 3));   

//generar un array con las letras de la palabra "Hola"
let saludos="Hola"
const chars = saludos.split("");
console.log("4. separado el string con espacio vacio: ",chars);  
console.log("\n\n")







// = == = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = 
console.clear()
//Elimina los espacio en blancos de los extremos de una cadena.
console.log("\n\n\n=============== MÃ©todo  trim, trimStart, trimEnd =========================")
let mensaje10="  el 7 de junio  "
let mensaje11="  el 7 de junio  "
let mensaje12="  el 7 de junio  "

console.log(mensaje10, mensaje10.length, "1. Trim      ",mensaje10.trim().length)
console.log(mensaje11, mensaje11.length, "2. trimStart ",mensaje11.trimStart().length)
console.log(mensaje12, mensaje12.length, "3. trimEnd   ",mensaje12. trimEnd().length)
console.log("\n\n")





// = == = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = 
console.clear()
//Retorna el caracter de una ubicaciÃ³n dada dentro de un string 
console.log("\n\n\n=============== at, =========================")
let ucm=     "CatÃ³lica"
let  numero= "01234567"

console.log(ucm)
console.log(numero)
console.log("Aplica mÃ©todo ucm.at(0)   de ",ucm, " es=", ucm.at(0),  " .Devuelve un caracter si existe")
console.log("Aplica mÃ©todo ucm.at(40)  de ",ucm, " es=", ucm.at(40), " .Devuelve undefined porque no existe la posiciÃ³n")
console.log("Aplica mÃ©todo ucm.at(-1)  de ",ucm, " es=", ucm.at(-1), " .Devuelve un caracter de la posicion 2, contando desde la derecha del string")
console.log("Aplica mÃ©todo ucm.at(-2)  de ",ucm, " es=", ucm.at(-2), " .Devuelve un caracter de la posicion 3, contando desde la derecha del string")
console.log("Aplica mÃ©todo ucm.at(-20) de ",ucm, " es=", ucm.at(-20)," .Devuelve undefined porque no existe la posiciÃ³n -20 desde la derecha del string ")

let ucm11="Universidad"
console.log("\n\n=============== charAt, =========================", ucm)
console.log("Aplica mÃ©todo ucm.charAt(0)   de ",ucm11, " es=", ucm11.charAt(0)   , " .Devuelve un caracter si existe")
console.log("Aplica mÃ©todo ucm.charAt(1)  de ",ucm11, " es=",  ucm11.charAt(1)    , " .Devuelve una cadena vacia porque la posicÃ³n estÃ¡ fuera de rango")
console.log("Aplica mÃ©todo ucm.charAt(2)  de ",ucm11, " es=",  ucm11.charAt(2)   , " .Devuelve una cadena vacia porque no acepta valores negativo")
console.log("Aplica mÃ©todo ucm.charAt(3)  de ",ucm11, " es=",  ucm11.charAt(3) , " .Devuelve una cadena vacia porque no acepta valores negativo")
console.log("Aplica mÃ©todo ucm.charAt(-3) de ",ucm11, " es=", ucm11.charAt(-3)    , " .Devuelve una cadena vacia porque no acepta valores negativo")

//ucm="abcde"
ucm="AZaz"

console.log("\n\n=============== charCodeAt,  el valor Unicode para cada letra, por ejemplo A=65, B=66 =========================")
console.log("Aplica mÃ©todo ucm.charCodeAt(0)   de ",ucm, " es=", ucm.charCodeAt(0))
console.log("Aplica mÃ©todo ucm.charCodeAt(1)   de ",ucm, " es=", ucm.charCodeAt(1))
console.log("Aplica mÃ©todo ucm.charCodeAt(2)   de ",ucm, " es=", ucm.charCodeAt(2))
console.log("Aplica mÃ©todo ucm.charCodeAt(3)  de ",ucm, " es=", ucm.charCodeAt(3))
console.log("Aplica mÃ©todo ucm.charCodeAt(-40) de ",ucm, " es=", ucm.charCodeAt(-40))
console.log("\n")
console.log("NaN significa 'Not-a-Number', es decir, No es un nÃºmero. ")
console.log("Se usa para indicar un resultado numÃ©rico invÃ¡lido, es decir, cuando una operaciÃ³n matemÃ¡tica no puede producir un nÃºmero vÃ¡lido.")
console.log("NaN pertenece al tipo number en JavaScript. Esto significa que NaN no es un tipo de dato, sino un valor especial dentro del tipo Number.")

console.log("\n\n")
 
 



// = == = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = 
console.clear()
//Retorna el caracter de una ubicaciÃ³n dada dentro de un string 
console.log("\n\n\n=============== startsWith y endWith =========================")

console.log("Talca     comienza con t? ", "Talca".startsWith("t"))
console.log("Talca     comienza con T? ", "Talca".startsWith("T"))
console.log("Talca     comienza con Tal? ", "Talca".startsWith("Tal"))
console.log("Talca     comienza con TAL? ", "Talca".startsWith("TAL"))
console.log("Talca     comienza con TalC? ", "Talca".startsWith("TalC"))

console.log("Santiago  comienza con sant? ", "Santiago".startsWith("sant"))
console.log("Santiago  comienza con San? ", "Santiago".startsWith("San"))
console.log("ChillÃ¡n   comienza con chi? ", "ChillÃ¡n".startsWith("chi"))
console.log("ChillÃ¡n   comienza con Chill? ", "ChillÃ¡n".startsWith("Chill"))

console.log("\n")
console.log("Talca     finaliza con a? ", "Talca".endsWith("ca"))
console.log("Talca     finaliza con lca? ", "Talca".endsWith("lca"))
console.log("Santiago  finaliza con iago? ", "Santiago".endsWith("iago"))
console.log("Santiago  finaliza con go? ", "Santiago".endsWith("go"))
console.log("ChillÃ¡n   finaliza con Ã¡n? ", "ChillÃ¡n".endsWith("Ã¡n"))
console.log("ChillÃ¡n   finaliza con N? ", "ChillÃ¡n".endsWith("N"))
console.log("\n")
 