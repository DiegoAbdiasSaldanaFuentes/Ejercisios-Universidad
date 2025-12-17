// Importamos el service encargado de la lógica de mensajes de grupo.
// Este controller es consumido por el router:
// /api/group-messages
const groupMessageService = require("../services/messagesService");

// ======================================
// GET /api/group-messages
// Obtiene todos los mensajes de grupos
// ======================================
const getAllGroupMessages = async (req, res) => {
  try {
    // Llamamos al service para traer todos los mensajes de grupo
    const messages = await groupMessageService.getAllGroupMessages();

    // Respondemos con éxito
    res.json({
      status: "success",
      data: messages
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
// POST /api/group-messages
// Crea un nuevo mensaje en un grupo
// ======================================
const createGroupMessage = async (req, res) => {
  try {
    // Enviamos el body al service
    // { id_grupo, emisor_rut, contenido }
    const insertId = await groupMessageService.createGroupMessage(req.body);

    // Respondemos con el ID creado
    res.json({
      status: "success",
      message: "Mensaje de grupo creado",
      id: insertId
    });
  } catch (err) {
    // Si el error viene con status (ej: 400), se respeta
    res.status(err.status || 500).json({
      status: "error",
      message: err.message || "Error interno"
    });
  }
};

// Exportamos para que lo use el router
module.exports = {
  getAllGroupMessages,
  createGroupMessage
};

