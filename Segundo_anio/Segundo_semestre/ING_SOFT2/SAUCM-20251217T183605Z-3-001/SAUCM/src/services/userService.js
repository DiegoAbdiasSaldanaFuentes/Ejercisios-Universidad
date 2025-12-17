const usersModel = require("../models/usersModel");

// Obtener todos los usuarios
const getAllUsers = async () => {
  return await usersModel.getAll();
};

// Crear usuario
const createUser = async (data) => {
  const { rut, nombre, correo, contrasena, tipo_usuario } = data;

  // Validación de negocio
  if (!rut || !nombre || !correo || !contrasena || !tipo_usuario) {
    throw {
      status: 400,
      message: "Faltan datos obligatorios"
    };
  }

  return await usersModel.create(data);
};

module.exports = {
  getAllUsers,
  createUser
};
