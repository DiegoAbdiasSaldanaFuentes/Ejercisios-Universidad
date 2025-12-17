const warningModel = require("../models/warningModel");

const getAllWarnings = async () => {
  return await warningModel.getAll();
};

const createWarning = async (data) => {
  const { usuario_rut, admin_rut, motivo } = data;

  if (!usuario_rut || !admin_rut || !motivo) {
    throw { status: 400, message: "Faltan datos" };
  }

  const insertId = await warningModel.create(usuario_rut, admin_rut, motivo);
  return insertId;
};

module.exports = { getAllWarnings, createWarning };
