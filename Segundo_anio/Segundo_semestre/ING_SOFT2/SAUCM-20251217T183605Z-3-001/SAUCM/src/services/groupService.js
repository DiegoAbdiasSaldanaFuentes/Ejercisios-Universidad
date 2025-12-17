const groupModel = require("../models/groupModel");

const getAllGroups = async () => {
  return await groupModel.getAllGroups();
};

// ======================================
// Crea un nuevo grupo
// ======================================
const createGroup = async (data) => {
  // 1. Validación: Verificamos que existan los campos obligatorios
  // (nombre del grupo y el RUT del usuario creador)
  if (!data.nombre || !data.creador_rut) {
    const error = new Error("Faltan datos obligatorios");
    error.status = 400; // Asignamos código 400 (Bad Request) porque faltan datos
    throw error;        // Lanzamos el error para que lo capture el controlador
  }

  // 2. Si la validación pasa, delegamos la inserción en la BD al modelo
  return await groupModel.createGroup(data);
};

// ======================================
// Actualizar grupo
// ======================================
const updateGroup = async (id, data) => {
  const { nombre, descripcion, privado } = data;

  // Validación: Debe venir al menos un dato para editar.
  // Nota: Para 'privado' revisamos que no sea undefined, ya que false es un valor válido.
  if (!nombre && !descripcion && privado === undefined) {
    const error = new Error("No se enviaron datos para actualizar");
    error.status = 400;
    throw error;
  }

  // Llamamos al modelo (asumiendo que crearás la función updateGroup ahí también)
  const affectedRows = await groupModel.updateGroup(id, data);

  if (affectedRows === 0) {
    const error = new Error("Grupo no encontrado");
    error.status = 404;
    throw error;
  }

  return affectedRows;
};

// ======================================
// Eliminar grupo (con validación de permisos)
// ======================================
/*const deleteGroup = async (groupId, currentUser) => {
  // 1. Buscamos el grupo para ver si existe y quién es el dueño
  const group = await groupModel.getGroupById(groupId);

  if (!group) {
    const error = new Error("Grupo no encontrado");
    error.status = 404;
    throw error;
  }
  // 2. LÓGICA DE PERMISOS:
  // Permitimos borrar SI:
  // - El RUT del usuario actual es igual al creador_rut del grupo (Es el Owner)
  // - O, el tipo_usuario es 'admin' (Es Administrador)
  const isOwner = group.creador_rut === currentUser.rut;
  const isAdmin = currentUser.tipo_usuario === 'admin'; // o el valor que uses para admins

  if (!isOwner && !isAdmin) {
    const error = new Error("No tienes permisos para eliminar este grupo");
    error.status = 403; // Forbidden (Prohibido)
    throw error;
  }

  // 3. Si pasó la validación, procedemos a borrar
  await groupModel.deleteGroup(groupId);
  
  return true; // Retornamos éxito
};*/

module.exports = {
  getAllGroups,
  createGroup,
  updateGroup,
  //deleteGroup
};
