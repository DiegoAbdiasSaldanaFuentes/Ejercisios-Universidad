


const actorModel = require("../models/actorModel")
const errorMap = require("../utils/errorMap");

//Recuoerando todos los registros de actores
exports.getAllActors= async()=>{
    return await actorModel.getAllActors()
}



// recuperando un resgitro de la tabla actor usando el id. 
exports.getActorById = async (idParam) => {
  // Validación: ID debe ser entero
  if (!/^\d+$/.test(idParam)) {
    const error = new Error(errorMap.BAD_REQUEST.message);
    error.statusCode = errorMap.BAD_REQUEST.status;
    error.type = errorMap.BAD_REQUEST.type;
    throw error;
  }

  const id = parseInt(idParam, 10);  // ojo: el 10 significa la base (decimal, binaria o hexadecimal). 10 representa a la base decimal. 2 representa binario y 16 a hexadecimal
  const actor = await actorModel.getActorById(id);

  if (!actor) {
    const error = new Error(errorMap.NOT_FOUND.message);
    error.statusCode = errorMap.NOT_FOUND.status;
    error.type = errorMap.NOT_FOUND.type;
    throw error;
  }

  return actor;
};


//Grabando un registro de aactor
exports.saveActor= async(data)=>{
   return await actorModel.saveActor(data)
}



 // ----- Servicio para actualizar un actor
exports.updateActor = async (idParam, data) => {
  // Validación: ID debe ser entero
  if (!/^\d+$/.test(idParam)) {
    const error = new Error(errorMap.BAD_REQUEST.message);
    error.statusCode = errorMap.BAD_REQUEST.status;
    error.type = errorMap.BAD_REQUEST.type;
    throw error;
  }

  const id = parseInt(idParam, 10);

  // Opcional: validar que haya campos a actualizar
  if (!data || Object.keys(data).length === 0) {
    const error = new Error("No se enviaron campos para actualizar");
    error.statusCode = errorMap.BAD_REQUEST.status;
    error.type = errorMap.BAD_REQUEST.type;
    throw error;
  }

  // affectedRows es un entero que inidca la cantidad de filas afectadas
  const affectedRows = await actorModel.updateActor(id, data);

  if (affectedRows === 0) {
    const error = new Error(errorMap.NOT_FOUND.message);
    error.statusCode = errorMap.NOT_FOUND.status;
    error.type = errorMap.NOT_FOUND.type;
    throw error;
  }

  // Devolvemos el registro actualizado desde la BD
  const updatedActor = await actorModel.getActorById(id);
  return updatedActor;
};



//------Servicio para borrar un actor
exports.deleteActor = async (idParam) => {
  // Validación: ID debe ser entero
  if (!/^\d+$/.test(idParam)) {
    const error = new Error(errorMap.BAD_REQUEST.message);
    error.statusCode = errorMap.BAD_REQUEST.status;
    error.type = errorMap.BAD_REQUEST.type;
    throw error;
  }

  const id = parseInt(idParam, 10);

  const affectedRows = await actorModel.deleteActor(id);

  if (affectedRows === 0) {
    const error = new Error(errorMap.NOT_FOUND.message);
    error.statusCode = errorMap.NOT_FOUND.status;
    error.type = errorMap.NOT_FOUND.type;
    throw error;
  }

  // Lo que devolverá el controller en success()
  return { deleted: true, actor_id: id };
};

 

// Helpers de validación simples
function isValidDate(str) {
  // Esperamos formato YYYY-MM-DD
  return /^\d{4}-\d{2}-\d{2}$/.test(str);
}

function isValidTime(str) {
  // Acepta HH:MM o HH:MM:SS
  return /^\d{2}:\d{2}(:\d{2})?$/.test(str);
}

// ✅ Servicio: actores por rango de fechas
exports.getActorsByDateRange = async (from, to) => {
  if (!isValidDate(from) || !isValidDate(to)) {
    const error = new Error("Formato de fecha inválido. Use YYYY-MM-DD.");
    error.statusCode = errorMap.BAD_REQUEST.status;
    error.type = errorMap.BAD_REQUEST.type;
    throw error;
  }

  // Opcional: validar que from <= to
  if (from > to) {
    const error = new Error("La fecha inicial no puede ser mayor que la fecha final.");
    error.statusCode = errorMap.BAD_REQUEST.status;
    error.type = errorMap.BAD_REQUEST.type;
    throw error;
  }

  const rows = await actorModel.getActorsByDateRange(from, to);
  return rows;
};

// ✅ Servicio: actores por rango de horas
exports.getActorsByTimeRange = async (from, to) => {
  if (!isValidTime(from) || !isValidTime(to)) {
    const error = new Error("Formato de hora inválido. Use HH:MM o HH:MM:SS.");
    error.statusCode = errorMap.BAD_REQUEST.status;
    error.type = errorMap.BAD_REQUEST.type;
    throw error;
  }

  // Normalizar a HH:MM:SS si viene como HH:MM
  const fromNorm = from.length === 5 ? `${from}:00` : from;
  const toNorm   = to.length === 5 ? `${to}:00`   : to;

  if (fromNorm > toNorm) {
    const error = new Error("La hora inicial no puede ser mayor que la hora final.");
    error.statusCode = errorMap.BAD_REQUEST.status;
    error.type = errorMap.BAD_REQUEST.type;
    throw error;
  }

  const rows = await actorModel.getActorsByTimeRange(fromNorm, toNorm);
  return rows;
};



// Consulta  nacionalidad = 'C' y salary entre [2Milones, 3Milones]
exports.getActorsByNationalityCAndSalaryRange = async () => {
  // Si quisieras más adelante validar rangos dinámicos, podríamos hacerlo aquí.
  const rows = await actorModel.getActorsByNationalityCAndSalaryRange();
  return rows;
};