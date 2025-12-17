const commentsModel = require("../models/commentsModel");

const getAllComments = async () => {
  return await commentsModel.getAllComments();
};

const createComment = async (data) => {
  const { archivo_id, autor_rut, contenido } = data;

  if (!archivo_id || !autor_rut || !contenido) {
    const error = new Error("Faltan datos obligatorios");
    error.status = 400;
    throw error;
  }

  return await commentsModel.createComment(data);
};

module.exports = {
  getAllComments,
  createComment
};
