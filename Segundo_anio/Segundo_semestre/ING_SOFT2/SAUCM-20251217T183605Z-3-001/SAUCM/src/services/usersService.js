const usersModel = require("../models/usersModel");

// ======================================
// Obtener todos los usuarios
// ======================================
const getAllUsers = async () => {
  return await usersModel.getAll();
};

// ======================================
// Crear usuario
// ======================================
const createUser = async (data) => {
  const { rut, nombre, correo, contrasena, tipo_usuario } = data;

  if (!rut || !nombre || !correo || !contrasena || !tipo_usuario) {
    throw { status: 400, message: "Faltan datos obligatorios" };
  }

  return await usersModel.create(data);
};

// ======================================
// Actualizar usuario (sin modificar el rut)
// ======================================

/*const updateUser = async (rut, data) => {
  const { nombre, correo, contrasena, tipo_usuario, foto_perfil } = data;

  // Validación: al menos un campo debe ser enviado
  if (!nombre && !correo && !contrasena && !tipo_usuario && foto_perfil === undefined) {
    throw { status: 400, message: "No se enviaron datos para actualizar" };
  }

  const affectedRows = await usersModel.updateUser(rut, data);

  if (affectedRows === 0) {
    throw { status: 404, message: "Usuario no encontrado" };
  }

  return affectedRows;
};*/

// ======================================
// Actualizar usuario (sin modificar rut ni correo)
// ======================================
const updateUser = async (rut, data) => {
  // 1. Quitamos 'correo' de aquí para que quede claro que no lo usamos
  const { nombre, contrasena, tipo_usuario, foto_perfil } = data;

  // 2. Quitamos '!correo' de la validación.
  // Así, si solo mandan 'correo', entrará en el error porque no hay nada válido que actualizar.
  if (!nombre && !contrasena && !tipo_usuario && foto_perfil === undefined) {
    throw { status: 400, message: "No se enviaron datos para actualizar" };
  }

  const affectedRows = await usersModel.updateUser(rut, data);

  if (affectedRows === 0) {
    throw { status: 404, message: "Usuario no encontrado" };
  }

  return affectedRows;
};

module.exports = {
  getAllUsers,
  createUser,
  updateUser
};

