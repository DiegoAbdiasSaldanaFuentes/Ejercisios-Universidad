/******************************************************
 * Codigos para probar:
 *  "SV2402", "AD2305", "BD2507", "OT2615", "A1B2C3D"
 ******************************************************/

let codigoServicio = "BD2507";



if(codigoServicio.length != 6){
    console.log("Código de servicio inválido, exceso de caracteres");
}else{
    switch (codigoServicio.substring(0)) {
        case "B"||"D":
            console.log("Servicio de Base de Datos");
            break;
        case "S"||"V":
            console.log("Servicio de Base de Datos");
            break;        
        case "A"||"D":
            console.log("Servicio de Asesoria digital");
            break;

        default:
            console.log("Codigo no enlistado");
            break;
    }


    let a = codigoServicio.charAt(4);
    let b = codigoServicio.charAt(5);
    parseInt(num = a+ b);

    if(num >= 1 && num<=2){
        console.log("Prioridad Alta");
    }
    else if(num >= 3 && num<=5){
        console.log("Prioridad Media");
    }
    else if(num >= 6 && num<=9){
        console.log("Prioridad Baja");
    }
    else if(num >= 10 && num<=99){
        console.log("Indefinido");
    }
};