function promesaEjemplo() {
    return new Promise((resolve, reject) => {
        setTimeout(() => {
            resolve("Hecho después de 2 segundos");
        }, 2000);
    });
}

async function ejecutar() {
    console.log("Inicio");
    let resultado = await promesaEjemplo();
    console.log(resultado);
    console.log("Fin");
}

ejecutar();
