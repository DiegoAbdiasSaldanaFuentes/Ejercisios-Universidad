// Importamos el pool de conexión a la base de datos
// Este pool se utiliza para ejecutar consultas MySQL
const pool = require("../config/db");

// ======================================
// Obtiene todos los grupos existentes
// ======================================
const getAllGroups = async () => {
  // Ejecutamos la consulta SQL para traer todos los grupos
  const [rows] = await pool.query("SELECT * FROM grupos");

  // Retornamos las filas obtenidas desde la base de datos
  return rows;
};

// ======================================
// Crea un nuevo grupo
// ======================================
const createGroup = async (group) => {
  // Desestructuramos los datos del grupo recibido
  const { nombre, descripcion, creador_rut, privado } = group;

  // Insertamos el nuevo grupo en la base de datos
  // descripcion puede ser null
  // privado por defecto es 0 (false)
  const [result] = await pool.query(
    "INSERT INTO grupos (nombre, descripcion, creador_rut, privado) VALUES (?, ?, ?, ?)",
    [nombre, descripcion || null, creador_rut, privado || 0]
  );

  // Retornamos el ID del grupo recién creado
  return result.insertId;
};

// ======================================
// Actualiza un grupo
// ======================================
const updateGroup = async (id, { nombre, descripcion, privado }) => {
  // COALESCE permite actualizaciones parciales:
  // Si 'nombre' viene null/undefined, se mantiene el valor original de la columna.
  const [result] = await pool.query(
    `UPDATE grupos 
     SET nombre = COALESCE(?, nombre),
         descripcion = COALESCE(?, descripcion),
         privado = COALESCE(?, privado)
     WHERE id = ?`,
    [nombre, descripcion, privado, id]
  );

  return result.affectedRows;
};

// ======================================
// Obtener un grupo por ID (Necesario para validar el dueño)
// ======================================
const getGroupById = async (id) => {
  const [rows] = await pool.query("SELECT * FROM grupos WHERE id = ?", [id]);
  return rows[0]; // Retorna el grupo o undefined si no existe
};

// ======================================
// Eliminar un grupo
// ======================================
/*const deleteGroup = async (id) => {
  const [result] = await pool.query("DELETE FROM grupos WHERE id = ?", [id]);
  return result.affectedRows;
};*/

// Exportamos las funciones del model
module.exports = {
  getAllGroups,
  createGroup,
  updateGroup,
  //deleteGroup
};

