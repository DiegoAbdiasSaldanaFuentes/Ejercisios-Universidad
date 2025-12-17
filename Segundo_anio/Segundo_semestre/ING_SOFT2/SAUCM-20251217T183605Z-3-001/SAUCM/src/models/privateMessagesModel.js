// Importamos el pool de conexión a la base de datos
// Se utiliza para ejecutar consultas MySQL
const pool = require("../config/db");

// ======================================
// Obtiene todos los mensajes privados
// ======================================
const getAll = async () => {
  // Ejecutamos la consulta SQL para traer todos los mensajes privados
  const [rows] = await pool.query("SELECT * FROM msj_privados");

  // Retornamos las filas obtenidas desde la base de datos
  return rows;
};

// ======================================
// Crea un nuevo mensaje privado
// ======================================
const create = async (emisor_rut, receptor_rut, contenido) => {
  // Insertamos el mensaje privado usando parámetros
  // emisor_rut: usuario que envía el mensaje
  // receptor_rut: usuario que recibe el mensaje
  // contenido: texto del mensaje
  const [result] = await pool.query(
    "INSERT INTO msj_privados (emisor_rut, receptor_rut, contenido) VALUES (?, ?, ?)",
    [emisor_rut, receptor_rut, contenido]
  );

  // Retornamos el ID del mensaje privado recién creado
  return result.insertId;
};

// Exportamos las funciones del model
module.exports = {
  getAll,
  create
};

