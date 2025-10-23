const contenido = "Hola, esto es JavaScript";

fs.writeFile('archivo_salida.txt', contenido, 'utf8', (err) => {
    if (err) {
        console.error("Error escribiendo archivo:", err);
        return;
    }
    console.log("Archivo creado exitosamente");
});
