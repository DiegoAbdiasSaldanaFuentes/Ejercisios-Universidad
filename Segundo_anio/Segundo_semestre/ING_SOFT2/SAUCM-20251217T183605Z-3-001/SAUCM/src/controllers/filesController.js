// Importamos el service de archivos.
// El controller no accede directamente a la base de datos.
const filesService = require("../services/filesService");

// ==============================
// GET /archivos
// Obtiene todos los archivos
// ==============================
const getAllFiles = async (req, res) => {
  try {
    // Llamamos al service para obtener todos los archivos
    const files = await filesService.getAllFiles();

    // Respondemos con éxito y enviamos los archivos obtenidos
    res.json({
      status: "success",
      data: files
    });
  } catch (err) {
    // Manejo de errores:
    // si el error tiene status lo usamos,
    // si no, se devuelve error interno (500)
    res.status(err.status || 500).json({
      status: "error",
      message: err.message
    });
  }
};

// ==============================
// POST /archivos
// Crea un nuevo archivo
// ==============================
const createFile = async (req, res) => {
  try {
    // Enviamos el body al service.
    // El service se encarga de validar los datos
    // e insertar el archivo en la base de datos
    const id = await filesService.createFile(req.body);

    // Respondemos indicando que el archivo fue creado
    // y devolvemos el id generado
    res.json({
      status: "success",
      message: "Archivo creado",
      id
    });
  } catch (err) {
    // Manejo de errores estandarizado
    res.status(err.status || 500).json({
      status: "error",
      message: err.message
    });
  }
};

// Exportamos las funciones del controller
// para que puedan ser utilizadas por el router
module.exports = {
  getAllFiles,
  createFile
};


