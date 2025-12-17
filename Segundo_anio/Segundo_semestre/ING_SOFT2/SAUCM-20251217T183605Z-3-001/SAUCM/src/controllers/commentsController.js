// Importamos el service de comentarios.
// El controller NO accede a la base de datos directamente.
const commentsService = require("../services/commentsService");

// ==============================
// GET /comentarios
// Obtiene todos los comentarios
// ==============================
const getAllComments = async (req, res) => {
  try {
    // Llamamos al service para obtener todos los comentarios
    const comments = await commentsService.getAllComments();

    // Respondemos con éxito y los datos obtenidos
    res.json({
      status: "success",
      data: comments
    });
  } catch (err) {
    // Si ocurre un error, devolvemos el status correspondiente
    // Si el error no tiene status, se asume error interno (500)
    res.status(err.status || 500).json({
      status: "error",
      message: err.message
    });
  }
};

// ==============================
// POST /comentarios
// Crea un nuevo comentario
// ==============================
const createComment = async (req, res) => {
  try {
    // Enviamos el body completo al service
    // El service se encarga de validar e insertar en la base de datos
    const id = await commentsService.createComment(req.body);

    // Respondemos indicando que el comentario fue creado
    // y devolvemos el id generado por la base de datos
    res.json({
      status: "success",
      message: "Comentario creado",
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
// para que puedan ser usadas en el router
module.exports = {
  getAllComments,
  createComment
};

