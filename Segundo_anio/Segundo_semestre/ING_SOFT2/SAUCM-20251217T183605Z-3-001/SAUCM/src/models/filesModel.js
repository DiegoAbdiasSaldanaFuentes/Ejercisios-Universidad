// Importamos el pool de conexión a la base de datos
// El pool permite reutilizar conexiones a MySQL
const pool = require("../config/db");

// ======================================
// Obtiene todos los archivos almacenados
// ======================================
const getAllFiles = async () => {
  // Ejecutamos la consulta SQL para traer todos los registros
  const [rows] = await pool.query("SELECT * FROM archivos");

  // Retornamos las filas obtenidas desde la base de datos
  return rows;
};

// ======================================
// Crea un nuevo archivo en la base de datos
// ======================================
const createFile = async ({ dueno_rut, nombre, ruta, descripcion }) => {
  // Insertamos un nuevo archivo usando parámetros
  // descripcion puede ser null si no se envía
  const [result] = await pool.query(
    "INSERT INTO archivos (dueno_rut, nombre, ruta, descripcion) VALUES (?, ?, ?, ?)",
    [dueno_rut, nombre, ruta, descripcion || null]
  );

  // Retornamos el ID del archivo recién creado
  return result.insertId;
};

// Exportamos las funciones del model
module.exports = {
  getAllFiles,
  createFile
};
