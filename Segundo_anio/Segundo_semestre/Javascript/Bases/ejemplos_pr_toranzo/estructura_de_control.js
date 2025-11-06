// programa que define los tipos de variables en Javascript
//=======CAMELCASE==============
/*
Carrera de IngenierÃ­a InformÃ¡tica 
Curso de IngenierÃ­a de software II
*/
/*

// = == = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = 
console.clear()
console.log("\n\n\n\n")
console.log("--------------------   IF   -------------------------------")
console.log("1. Ejemplo: if ")
let edad1= Math.round(Math.random())
console.log("La edad de la personas es: ", edad1)
if(edad1 <18){
    console.log("La persona es menor de edad")
}
else{
    console.log("la persona es mayor de edad")
}



console.log("\n\n")
console.log("2. ======= Ejemplo de if para determinar el color de un auto =======")
console.log("=".repeat(50))
console.log("Un auto tiene 4 opciones de colores: rojo, amarillo, azul y verde")
let color = "rojo"   //color validados: rojo, amarillo, azul y verde
let resultado= "El color encontrado es"
console.log("El color inicial es ", color)

if(color =="rojo"){
         color="rojo"
    }
else if (color=="amarillo"){
        color="amarillo"
    }
else if (color=="azul"){
        color=="azul"
    }
else if (color=="verde"){
        color="verde"
    }    
else{
        resultado="No existe color: " 
} 
console.log(resultado, color)
console.log("\n\n")

*/

/*
let origen = 1 + Math.round(Math.random()*4);
let destino = 1 +Math.round(Math.random()*4);
valorMinuto = 100;
let duracion = 1 + Math.round(Math.random()*9);
let valor = 0;
if(origen == destino){
  valor = 100;
}
else if(origen == 1){
  valor = 1000;
}
else if(origen == 2){
  valor = 2000;
}
else if(origen == 3){
  valor =  3000;
}
else if(origen == 4){
  valor = 4000;
}
else if(origen == 5){
  valor = 5000
}



Hora [1 a 8] =10% es de madrugada
Hora [8 , 16] = 15% buen dia
Hora [16 ,24] = 20% buenas noches


console.log("registro de llamada", origen, " ",destino," ", duracion," ", valor, " ");
*/

/*
console.clear()
console.log("\n")
console.log("================= if ternario===========================")
console.log("Sintaxis    condiciÃ³n ? valor_si_verdadero : valor_si_falso;")
console.log("            Si la condiciÃ³n es verdadera (true), se ejecuta el primer valor")
console.log("            Si la condiciÃ³n es falsa (false),    se ejecuta el segundo valor")

console.log("\n")
let edad = 10;
console.log("1. Determinando si es o no mayor de edad ")
console.log("La edad de la persona es ", edad)
let mensaje = (edad >= 18) ? "Es mayor de edad" : "Es menor de edad";
console.log("La determinaciÃ³n es : ", mensaje); 
console.log("\n")

console.log("\n 2. ==== lo mismo pero aplicando valor aleatorio")
edad =  Math.round(Math.random()*110);
console.log("2. Determinando si es o no mayor de edad ")
console.log("La edad de la persona es ", edad)
mensaje = (edad >= 18) ? "Es mayor de edad" : "Es menor de edad";
console.log("La determinaciÃ³n es : ", mensaje); 
console.log("\n")

*/

/*
console.log("\n 3. ==== Aletorio para saber si es hombre o mujer")
let sexo  =  Math.round(Math.random());
let mensajeSexo = (sexo == 1) ? "Hombre" : "Mujer";
console.log("El sexo es : ", mensajeSexo); 

console.log("\n")
*/

/*

console.log("\n 4. ==== Aletorio para determinar el estado de un clima: Caluroso(>30), Agradable(>=15) o FrÃ­o")
let temperatura = Math.round(Math.random()*40);
console.log("\n La temperatura generada: ", temperatura)
let estado = (temperatura > 30) ? "Caluroso" : (temperatura >= 15) ? "Agradable" : "FrÃ­o";
console.log(estado); 
console.log("\n")

*/

/*



console.log("\n")
console.log("5. ===== Ejemplo de ? para determinar el color de un auto ======================")
console.log("Un auto tiene 4 opciones de colores: rojo, amarillo, azul y verde")
let color = "amarillo"   //color validados: rojo, amarillo, azul y verde
console.log("El color inicial es ", color)
let resultado = (color =="rojo")
                    ?"rojo"
                :(color =="amarillo")
                    ?"amarillo"
                :(color =="azul")
                        ?"azul"
                :(color =="verde")
                            ?"verde"
                :"Color inexistente"
 console.log("El resultado es: ",resultado)
console.log("\n\n")








console.clear()
console.log("\n")
console.log("========= Sentencia Switch ======================")

console.log("1. Ejemplo  de switch manipulando entero")
let numeroSwitch= 1
switch(numeroSwitch){
    case 1: console.log("El valor es 1")
            break
    case 2: console.log("El valor es 2")
            break         
    case 3: console.log("El valor es 3")
            break
    default: console.log("Valor no encontrado!!")
}

*/

/*

console.log("\n")
console.log("2. Ejemplo  de switch manipulando intervalos de numeros")
let puntaje = 8;

switch (true) {
  case (puntaje >= 1 && puntaje <= 3):
    console.log("Nivel: Bajo");
    break;

  case (puntaje >= 4 && puntaje <= 6):
    console.log("Nivel: Medio");
    break;

  case (puntaje >= 7 && puntaje <= 10):
    console.log("Nivel: Alto");
    break;

  default:
    console.log("Puntaje fuera de rango");
}

*/

/*


console.log("\n")
console.log("3. Ejemplo  de switch manipulando string")
let nombreFruta="Mango"
console.log("La fruta es ", nombreFruta)
switch (nombreFruta) {
  case "Naranja":
        console.log("El kilogramo de naranjas cuesta $0.59.");
        break;
  case "Manzana":
        console.log("El kilogramo de manzanas cuesta $0.32.");
        break;
  case "Platano":
        console.log("El kilogramo de platanos cuesta $0.48.");
        break;
  case "Cereza":
        console.log("El kilogramo de cerezas cuesta $3.00.");
        break;
  case "Mango":
  case "Papaya":
        console.log("El kilogramo de mangos y papayas cuesta $2.79.");
        break;
  default:
    console.log("Fruta no existente= " + nombreFruta + ".");
}

console.log("\n")
console.log("4. Ejemplo de switch manipulando valores booleano")
let nota = (1+ Math.random()*6).toFixed(1);
console.log("Nota a conceptualizar  ", nota)
switch (true) {
  case (nota >= 6 && nota <= 7):
    console.log("Excelente");
    break;
  case (nota >= 5 && nota < 5.9):
    console.log("Bueno");
    break;
  case (nota >= 4 && nota < 4,9):
    console.log("Regular");
    break;
  default:
    console.log("Deficiente");
}
*/

console.clear()
console.log("\n")
console.log("================ EJERCICIO ======================")
console.log("El siguiente abecedario fue divido en 4 partes:  a, b, c, d, e, f, g, h, i, j, k, l, m, n, Ã±, o, p, q, r, s, 4) t, u, v, w, x, y, z")
console.log("Parte 1: a, b, c, d, ")
console.log("Parte 2: e, f, g, h, i, j, ")
console.log("Parte 3: k, l, m, n, Ã±, o, p")
console.log("Parte 4: q, r, s, 4) t, u, v, w, x, y, z")

let letraIngresada= "a"
console.log("LA soluciÃ³n aplica solamente todo lo visto hasta el momento. La persona ingresarÃ¡ una letra y su soluciÃ³n deberÃ¡ indicar el nÃºmero de la parte donde estÃ¡ la localizada la letra")    

switch (true) {
  case letraIngresada.charAt(0):
    console.log("si esta ahi");
    break;

  default:
    break;
}

/*
//Ejempo 1
console.clear()
console.log("\n\n\n")
console.log("Ejercicio Math.round, Math.ceil y Math.floor")
console.log("usando Math.round(numeroDecimal): aproxima al entero mÃ¡s cercano. De .5 hacia arriba redondea hacia ARRIBA")
console.log("1. Math.round(17.3)= ",Math.round(17.3))
console.log("2. Math.round(17.5)= ",Math.round(17.5))
console.log("3. Math.round(17.7)= ",Math.round(17.7))
 
console.log("\n")
console.log("usando Math.ceil(numeroDecimal): REDONDEA siempre hacia ARRIBA")
console.log("1. Math.ceil(17.3)= ",Math.ceil(17.1))
console.log("2. Math.ceil(17.5)= ",Math.ceil(17.4))
console.log("3. Math.ceil(17.7)= ",Math.ceil(17.7))


console.log("\n")
console.log("usando Math.floor(numeroDecimal): REDONDEA siempre hacia ABAJO")
console.log("1. Math.floor(17.3)= ",Math.floor(17.1))
console.log("2. Math.floor(17.5)= ",Math.floor(17.4))
console.log("3. Math.floor(17.7)= ",Math.floor(17.7))

console.log("\n\n")








//
console.log("\n\n")
console.log("Ejercicio: Determina el concepto asociado a un concepto")
let notaPersona=1
console.log("Intervalo   Concepto")
console.log("7           Muy bueno")
console.log("6,0 a 6,9   Bueno")
console.log("4,0 a 5,9   Regular")
console.log("1 a 3,9     Deficiente")
console.log("El concepto es= ")
console.log("\n\n")







console.log("\n\n")
console.log("Ejercicio: determina el descuento de una compra")
console.log("La tabla de descuento de una empresa chinea que vende de celular al por mayor es la siguiente")
console.log("valores estÃ¡n en miles")
console.log("  Intervalos    Descuentos")
console.log("  [1   -  99]        0%]")
console.log("  [100 - 199]       1%")
console.log("  [200 - 299]       2%")
console.log("  [300 - 399]       3%")
console.log("  [400 - 499]       4%")
console.log("  [500 - 599]       7%")
console.log("  [600 - 699]       8%")
console.log("  [700 - 799]       9%")
console.log("  [800 - 10000)     10%")

//Math.random() genera un valor aletorio entre 0 y 1

let cantidadCelulares= 1 + Math.floor(Math.random()*(10000 -1)*100)
let valorUnitarioCelular= 50000
let valorTotalCompra= cantidadCelulares * valorUnitarioCelular


const formateo = new Intl.NumberFormat('en-US', {
          style: 'currency',
          currency: 'USD',
          minimumFractionDigits: 0
        });

        
//sin  .toLocaleString()  
console.log("Formato aplicando formato de  estado unidos")
console.log("                                          Total de celulares comprado= ",cantidadCelulares)

//con  .toLocaleString()     
console.log("(Aplicando configuracion de usuario)         Total de celulares comprado= ",cantidadCelulares.toLocaleString())
//con  formateo      
console.log("Valor total de la compra (usando moneda de 'estado unidos')= ",formateo.format(valorTotalCompra) )
console.log("Valor total de la compra (usando moneda de \"estado unidos\")= ",formateo.format(valorTotalCompra) )


console.log("\n\n")
console.log("Formato aplicando formato de  Chile")
console.log("                                          Total de celulares comprado= ",cantidadCelulares)

//con  .toLocaleString()     
console.log("(Aplicando configuracion de usuario)         Total de celulares comprado= ",cantidadCelulares.toLocaleString())
//con  formateo      
console.log("Valor total de la compra (usando moneda de 'estado unidos')= ",formateo.format(valorTotalCompra) )
console.log("Valor total de la compra (usando moneda de \"estado unidos\")= ",formateo.format(valorTotalCompra) )


*/




