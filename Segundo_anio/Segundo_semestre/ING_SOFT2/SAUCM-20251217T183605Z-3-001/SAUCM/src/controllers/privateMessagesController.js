// Importamos el service que maneja la lógica de los mensajes privados.
// El controller solo se encarga de recibir la petición y devolver la respuesta.
const privateMessageService = require("../services/privateMessagesService");

// ======================================
// GET /mensajes-privados
// Obtiene todos los mensajes privados
// ======================================
const getAllPrivateMessages = async (req, res) => {
  try {
    // Llamamos al service para obtener todos los mensajes privados
    const messages = await privateMessageService.getAllPrivateMessages();

    // Respondemos con éxito y enviamos los mensajes
    res.json({
      status: "success",
      data: messages
    });
  } catch (err) {
    // Error interno del servidor
    res.status(500).json({
      status: "error",
      message: err.message || "Error interno"
    });
  }
};

// ======================================
// POST /mensajes-privados
// Crea un nuevo mensaje privado
// ======================================
const createPrivateMessage = async (req, res) => {
  try {
    // Enviamos el body al service para crear el mensaje privado
    // (emisor_rut, receptor_rut, contenido)
    const insertId = await privateMessageService.createPrivateMessage(req.body);

    // Respondemos indicando que el mensaje fue creado
    // y devolvemos el ID generado en la base de datos
    res.json({
      status: "success",
      message: "Mensaje privado creado",
      id: insertId
    });
  } catch (err) {
    // Manejo de errores:
    // si el service define un status, se utiliza
    // si no, se devuelve error interno (500)
    res.status(err.status || 500).json({
      status: "error",
      message: err.message || "Error interno"
    });
  }
};

// Exportamos las funciones para que puedan ser usadas en el router
module.exports = {
  getAllPrivateMessages,
  createPrivateMessage
};


