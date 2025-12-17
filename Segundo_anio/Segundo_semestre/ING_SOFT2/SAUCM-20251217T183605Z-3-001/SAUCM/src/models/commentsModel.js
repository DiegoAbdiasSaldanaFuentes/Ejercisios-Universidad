// Importamos el pool de conexión a la base de datos
// Este pool se configura en /config/db.js
const pool = require("../config/db");

// ======================================
// Obtiene todos los comentarios de archivos
// (Acceso directo a la base de datos)
// ======================================
const getAllComments = async () => {
  // Ejecutamos la consulta SQL para traer todos los registros
  const [rows] = await pool.query(
    "SELECT * FROM comentarios_archivos"
  );

  // Retornamos las filas obtenidas
  return rows;
};

// ======================================
// Crea un nuevo comentario en un archivo
// ======================================
const createComment = async ({ archivo_id, autor_rut, contenido }) => {
  // Ejecutamos el INSERT usando parámetros para evitar SQL Injection
  const [result] = await pool.query(
    "INSERT INTO comentarios_archivos (archivo_id, autor_rut, contenido) VALUES (?, ?, ?)",
    [archivo_id, autor_rut, contenido]
  );

  // Retornamos el ID del comentario recién creado
  return result.insertId;
};

// Exportamos las funciones del model
module.exports = {
  getAllComments,
  createComment
};

