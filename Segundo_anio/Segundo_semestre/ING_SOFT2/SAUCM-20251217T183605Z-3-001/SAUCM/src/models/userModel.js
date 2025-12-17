const pool = require("../config/db");

// Obtener todos los usuarios
const getAll = async () => {
  const [rows] = await pool.query(
    "SELECT rut, nombre, correo, tipo_usuario, foto_perfil FROM usuarios"
  );
  return rows;
};

// Crear usuario
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

module.exports = {
  getAll,
  create
};
