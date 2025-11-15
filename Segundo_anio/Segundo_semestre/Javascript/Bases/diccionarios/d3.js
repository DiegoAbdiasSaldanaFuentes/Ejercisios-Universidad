const usuarios = new Map();

// Agregar datos
usuarios.set("diego", { edad: 19, rol: "Estudiante" });
usuarios.set("maria", { edad: 22, rol: "Diseñadora" });

// Acceder
console.log(usuarios.get("diego")); // { edad: 19, rol: "Estudiante" }

// Verificar existencia
console.log(usuarios.has("maria")); // true

// Eliminar
usuarios.delete("diego");

// Recorrer
for (let [clave, valor] of usuarios) {
  console.log(clave, valor);
}
