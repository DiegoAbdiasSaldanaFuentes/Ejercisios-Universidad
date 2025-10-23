class Estudiante extends Persona {
    constructor(nombre, edad, carrera) {
        super(nombre, edad); // llama al constructor de la clase base
        this.carrera = carrera;
    }

    estudiar() {
        console.log(`${this.nombre} está estudiando ${this.carrera}`);
    }
}

const juan = new Estudiante("Juan", 20, "Informática");
juan.saludar();
juan.estudiar();
