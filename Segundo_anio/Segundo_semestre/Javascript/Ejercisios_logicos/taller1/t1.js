/*1.	Una cadena de supermercado quiere simular los totales de ventas mensuales de sus siete sucursales. Diseño un programa Javascript que:
a.	Genere valores aleatorios enteros entre 30 y 70 (expresan millones). 
b.	General un gráfico de barra horizontal 
*/

let sucursales=7;
for(let i= 1; i<=sucursales;i++){
    let ventas=30+Math.round(Math.random()*40);
    let string = "#";
    resultado = string.repeat(ventas);


    console.log("Sucursal-",i,resultado,ventas);
};
