// Importamos el service encargado de la lógica de advertencias
const warningService = require("../services/warningService");

// ======================================
// GET /api/warnings
// Obtiene todas las advertencias registradas
// ======================================
const getAllWarnings = async (req, res) => {
  try {
    // Llamamos al service para obtener todas las advertencias desde la BD
    const warnings = await warningService.getAllWarnings();

    // Respondemos con éxito y enviamos los datos
    res.json({
      status: "success",
      data: warnings
    });
  } catch (err) {
    // Error genérico del servidor
    res.status(500).json({
      status: "error",
      message: err.message || "Error interno"
    });
  }
};

// ======================================
// POST /api/warnings
// Crea una nueva advertencia para un usuario
// ======================================
const createWarning = async (req, res) => {
  try {
    // Enviamos el body al service para crear la advertencia
    // (usuario_rut, admin_rut, motivo)
    const insertId = await warningService.createWarning(req.body);

    // Respondemos indicando que la advertencia fue creada correctamente
    res.json({
      status: "success",
      message: "Advertencia creada",
      id: insertId
    });
  } catch (err) {
    // Si el service lanza un error con status, lo respetamos
    res.status(err.status || 500).json({
      status: "error",
      message: err.message || "Error interno"
    });
  }
};

// Exportamos los métodos del controller
module.exports = {
  getAllWarnings,
  createWarning
};

