let persona = {
    nombre: "Diego",
    edad: 22,
    profesion: "Estudiante",
    saludar: function() {
        console.log("Hola, soy " + this.nombre);
    }
};

console.log(persona.nombre);
persona.saludar();
