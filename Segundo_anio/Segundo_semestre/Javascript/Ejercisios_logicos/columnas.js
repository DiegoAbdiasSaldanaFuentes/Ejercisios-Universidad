let cl = 10;
let pe = 5;
let ar = 15;


let alturaMaxima = 15; 

console.log("\nGRAFICO VERTICAL\n");


for (let piso = alturaMaxima; piso >= 1; piso--) {
    
    let linea = ""; 
    

    if (cl >= piso) {
        linea += " * ";
    } 
    else{
        linea += "   "; 
    }
    
    if (pe >= piso) {
        linea += "    * ";
    } 
    else{
        linea += "     "; 
    }
    if (ar >= piso) {
        linea += "    *";
    } 
    else{
        linea += "  "; 

    }
    console.log(linea);
}

console.log(" CL   PE   AR");