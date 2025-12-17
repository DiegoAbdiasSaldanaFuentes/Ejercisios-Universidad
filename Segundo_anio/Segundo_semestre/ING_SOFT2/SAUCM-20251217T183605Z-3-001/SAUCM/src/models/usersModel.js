// Importamos el pool de conexión a la base de datos
const pool = require("../config/db");

// ======================================
// Obtiene todos los usuarios
// ======================================
const getAll = async () => {
  const [rows] = await pool.query(
    "SELECT rut, nombre, correo, tipo_usuario, foto_perfil FROM usuarios"
  );
  return rows;
};

// ======================================
// Crea un nuevo usuario
// ======================================
const create = async (user) => {
  const { rut, nombre, correo, contrasena, tipo_usuario, foto_perfil } = user;

  const [result] = await pool.query(
    `INSERT INTO usuarios 
     (rut, nombre, correo, contrasena, tipo_usuario, foto_perfil)
     VALUES (?, ?, ?, ?, ?, ?)`,
    [rut, nombre, correo, contrasena, tipo_usuario, foto_perfil || null]
  );

  return result;
};

// ======================================
// Actualiza un usuario (sin modificar el rut)
// ======================================
/* const updateUser = async (rut, { nombre, correo, contrasena, tipo_usuario, foto_perfil }) => {
  const [result] = await pool.query(
    `UPDATE usuarios
     SET nombre = ?, correo = ?, contrasena = ?, tipo_usuario = ?, foto_perfil = ?
     WHERE rut = ?`,
    [nombre, correo, contrasena, tipo_usuario, foto_perfil || null, rut]
  );
  return result.affectedRows; // devuelve cuántas filas fueron modificadas
};*/

const updateUser = async (rut, { nombre, contrasena, tipo_usuario, foto_perfil }) => {
  // Nota: Aunque el objeto recibido traiga 'correo', lo ignoramos en la desestructuración
  // y no lo incluimos en la query.

  const [result] = await pool.query(
    `UPDATE usuarios
     SET nombre = ?, contrasena = ?, tipo_usuario = ?, foto_perfil = ?
     WHERE rut = ?`,
    [nombre, contrasena, tipo_usuario, foto_perfil || null, rut]
  );
  
  return result.affectedRows;
};

// Exportamos todas las funciones del model
module.exports = {
  getAll,
  create,
  updateUser
};