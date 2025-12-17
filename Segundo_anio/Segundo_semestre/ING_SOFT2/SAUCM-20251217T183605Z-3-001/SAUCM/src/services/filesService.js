const filesModel = require("../models/filesModel");

const getAllFiles = async () => {
  return await filesModel.getAllFiles();
};

const createFile = async (data) => {
  const { dueno_rut, nombre, ruta } = data;

  if (!dueno_rut || !nombre || !ruta) {
    const error = new Error("Faltan datos obligatorios");
    error.status = 400;
    throw error;
  }

  return await filesModel.createFile(data);
};

module.exports = {
  getAllFiles,
  createFile
};
