const fs = require('fs');

fs.readFile('archivo.txt', 'utf8', (err, data) => {
    if (err) {
        console.error("Error leyendo archivo:", err);
        return;
    }
    console.log("Contenido del archivo:", data);
});
