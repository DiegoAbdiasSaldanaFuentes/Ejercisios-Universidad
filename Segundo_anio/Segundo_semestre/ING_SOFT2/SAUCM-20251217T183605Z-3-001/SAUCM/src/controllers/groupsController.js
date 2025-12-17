// Importamos el service de grupos.
// El controller se encarga solo de manejar la petición y la respuesta,
// no de la lógica ni del acceso a la base de datos.
const groupService = require("../services/groupService");

// ==============================
// GET /grupos
// Obtiene todos los grupos
// ==============================
const getAllGroups = async (req, res) => {
  try {
    // Llamamos al service para obtener todos los grupos
    const groups = await groupService.getAllGroups();

    // Respondemos con éxito y enviamos los grupos obtenidos
    res.json({
      status: "success",
      data: groups
    });
  } catch (err) {
    // Manejo de errores:
    // si el error viene con status, lo usamos,
    // si no, devolvemos error interno (500)
    res.status(err.status || 500).json({
      status: "error",
      message: err.message
    });
  }
};

// ==============================
// POST /grupos
// Crea un nuevo grupo
// ==============================
const createGroup = async (req, res) => {
  try {
    // Enviamos el body al service.
    // El service valida los datos (nombre, creador, etc.)
    // y crea el grupo en la base de datos
    const id = await groupService.createGroup(req.body);

    // Respondemos indicando que el grupo fue creado
    // y devolvemos el id generado
    res.json({
      status: "success",
      message: "Grupo creado",
      id
    });
  } catch (err) {
    // Manejo de errores estandarizado
    res.status(err.status || 500).json({
      status: "error",
      message: err.message
    });
  }
};

// ======================================
// PUT /groups/:id
// Actualiza la información de un grupo
// ======================================
const updateGroup = async (req, res, next) => {
  try {
    const { id } = req.params; // Asumimos que la URL es /groups/1, /groups/2, etc.
    const data = req.body;     // { nombre, descripcion, privado }

    // Llamamos al servicio
    const affectedRows = await groupService.updateGroup(id, data);

    res.json({
      status: "success",
      message: "Grupo actualizado correctamente",
      affectedRows
    });
  } catch (err) {
    next(err); // Pasa errores (como el 404 o 400) al middleware de errores
  }
};

// ======================================
// DELETE /groups/:id
// ======================================
/*const deleteGroup = async (req, res, next) => {
  try {
    const { id } = req.params;
    
    // IMPORTANTE: Asumimos que tienes un middleware de autenticación
    // que coloca los datos del usuario en req.user.
    // Si no lo tienes, tendrías que enviar el rut/tipo en el body (no recomendado por seguridad).
    const currentUser = req.user; 

    // Validación extra por si acaso no hay usuario logueado
    if (!currentUser) {
       throw { status: 401, message: "Usuario no autenticado" };
    }

    await groupService.deleteGroup(id, currentUser);

    res.json({
      status: "success",
      message: "Grupo eliminado correctamente"
    });
  } catch (err) {
    next(err);
  }
};*/

// Exportamos las funciones del controller
// para que puedan ser utilizadas por el router
module.exports = {
  getAllGroups,
  createGroup,
  updateGroup,
  //deleteGroup
};

