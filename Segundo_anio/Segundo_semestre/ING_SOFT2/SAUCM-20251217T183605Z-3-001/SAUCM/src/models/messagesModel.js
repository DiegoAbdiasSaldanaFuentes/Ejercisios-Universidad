// El model es la única capa que accede a la base de datos
const pool = require("../config/db");

// ======================================
// Obtener todos los mensajes de grupos
// ======================================
const getAll = async () => {
  const [rows] = await pool.query(
    "SELECT * FROM msj_grupos"
  );
  return rows;
};

// ======================================
// Crear un mensaje en un grupo
// ======================================
const create = async (id_grupo, emisor_rut, contenido) => {
  const [result] = await pool.query(
    "INSERT INTO msj_grupos (id_grupo, emisor_rut, contenido) VALUES (?, ?, ?)",
    [id_grupo, emisor_rut, contenido]
  );

  return result.insertId;
};

module.exports = {
  getAll,
  create
};


