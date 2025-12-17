const privateMessageModel = require("../models/privateMessagesModel");

const getAllPrivateMessages = async () => {
  return await privateMessageModel.getAll();
};

const createPrivateMessage = async (data) => {
  const { emisor_rut, receptor_rut, contenido } = data;

  if (!emisor_rut || !receptor_rut || !contenido) {
    throw { status: 400, message: "Faltan datos" };
  }

  const insertId = await privateMessageModel.create(emisor_rut, receptor_rut, contenido);
  return insertId;
};

module.exports = { getAllPrivateMessages, createPrivateMessage };
