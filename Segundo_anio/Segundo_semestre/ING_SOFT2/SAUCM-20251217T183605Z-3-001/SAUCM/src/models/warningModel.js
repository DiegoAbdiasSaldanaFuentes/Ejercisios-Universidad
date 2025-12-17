// Importamos el pool de conexión a la base de datos
// Se utiliza para ejecutar consultas MySQL
const pool = require("../config/db");

// ======================================
// Obtiene todas las advertencias
// ======================================
const getAll = async () => {
  // Ejecutamos la consulta SQL para traer todas las advertencias
  const [rows] = await pool.query("SELECT * FROM advertencias");

  // Retornamos las filas obtenidas desde la base de datos
  return rows;
};

// ======================================
// Crea una nueva advertencia
// ======================================
const create = async (usuario_rut, admin_rut, motivo) => {
  // Insertamos la advertencia usando parámetros
  // usuario_rut: usuario advertido
  // admin_rut: administrador que emite la advertencia
  // motivo: razón de la advertencia
  const [result] = await pool.query(
    "INSERT INTO advertencias (usuario_rut, admin_rut, motivo) VALUES (?, ?, ?)",
    [usuario_rut, admin_rut, motivo]
  );

  // Retornamos el ID de la advertencia recién creada
  return result.insertId;
};

// Exportamos las funciones del model
module.exports = {
  getAll,
  create
};

