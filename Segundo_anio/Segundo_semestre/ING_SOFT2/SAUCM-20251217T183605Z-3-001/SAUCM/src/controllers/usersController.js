// Importamos el service que contiene la lógica de negocio relacionada con usuarios
const usersService = require("../services/usersService");

// ======================================
// GET /api/users
// Obtiene todos los usuarios del sistema
// ======================================
const getAllUsers = async (req, res, next) => {
  try {
    // Llamamos al service para traer todos los usuarios desde la base de datos
    const users = await usersService.getAllUsers();

    // Respondemos con éxito y enviamos el listado de usuarios
    res.json({
      status: "success",
      data: users
    });
  } catch (err) {
    // Si ocurre un error, lo enviamos al middleware de errores
    next(err);
  }
};

// ======================================
// POST /api/users
// Crea un nuevo usuario
// ======================================
const createUser = async (req, res, next) => {
  try {
    // Enviamos el body al service para crear el usuario
    // (rut, nombre, correo, contraseña, tipo_usuario, foto_perfil)
    await usersService.createUser(req.body);

    // Respondemos con estado 201 (creado correctamente)
    res.status(201).json({
      status: "success",
      message: "Usuario creado"
    });
  } catch (err) {
    // Cualquier error se pasa al middleware de errores
    next(err);
  }
};

// ======================================
// PUT /users/:rut
// Actualiza un usuario existente (excepto el RUT)
// ======================================
/*const updateUser = async (req, res, next) => {
  try {
    const { rut } = req.params; // RUT del usuario a actualizar
    const data = req.body; // Campos a actualizar: nombre, correo, contrasena, tipo_usuario, foto_perfil

    const affectedRows = await usersService.updateUser(rut, data);

    res.json({
      status: "success",
      message: "Usuario actualizado",
      affectedRows
    });
  } catch (err) {
    next(err); // pasa el error al middleware
  }
};*/

const updateUser = async (req, res, next) => {
  try {
    const { rut } = req.params; 
    const data = req.body; // Campos: nombre, contrasena, tipo_usuario, foto_perfil (correo se ignora)

    const affectedRows = await usersService.updateUser(rut, data);

    res.json({
      status: "success",
      message: "Usuario actualizado",
      affectedRows
    });
  } catch (err) {
    next(err); 
  }
};

// Exportamos las funciones para que puedan ser usadas en el router
module.exports = {
  getAllUsers,
  createUser,
  updateUser
};

