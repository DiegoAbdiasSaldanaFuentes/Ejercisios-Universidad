// El service contiene la lógica de negocio
// y es utilizado por el controller de /api/group-messages
const groupMessageModel = require("../models/messagesModel");

// ======================================
// Obtener todos los mensajes de grupo
// ======================================
const getAllGroupMessages = async () => {
  return await groupMessageModel.getAll();
};

// ======================================
// Crear un mensaje de grupo
// ======================================
const createGroupMessage = async (data) => {
  const { id_grupo, emisor_rut, contenido } = data;

  // Validaciones mínimas (responsabilidad del service)
  if (!id_grupo || !emisor_rut || !contenido) {
    throw {
      status: 400,
      message: "Faltan datos obligatorios"
    };
  }

  // Llamamos al model para insertar en la BD
  const insertId = await groupMessageModel.create(
    id_grupo,
    emisor_rut,
    contenido
  );

  return insertId;
};

module.exports = {
  getAllGroupMessages,
  createGroupMessage
};

