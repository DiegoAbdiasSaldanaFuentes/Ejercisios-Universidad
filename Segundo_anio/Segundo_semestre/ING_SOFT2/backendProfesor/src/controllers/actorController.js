

const actorService = require("../services/actorService")
const { success } = require("../utils/apiResponse");
const asyncHandler = require("../middleware/asyncHandler")



//"Recupera todos" los registros de la tabla actor
// req=todos los datos proveniente del front. En este caso enviado por thunder clien, postman o igsonia 
exports.getAllActors = asyncHandler(async (req, res) => {
  const rows = await actorService.getAllActors()
  success(res, rows, "Actores obtenidos exitosamente")
})


//"Recupera un" registro usando Id (la clave primaria)
exports.getActorById = asyncHandler(async (req, res) => {
  const row = await actorService.getActorById(req.params.id)
 
  success(res, row, "Registro recuperado exitosamente")
})



//Grbando un actor en la tabla. 
exports.saveActor = asyncHandler(async (req, res) => {
  const nuevoActor = await actorService.saveActor(req.body);
  success(res, nuevoActor, "Actor creado exitosamente");
});


 // ----Actualización de un registro de la tabla actor
exports.updateActor = asyncHandler(async (req, res) => {
  const actorId = req.params.id; // ID desde la URL
  const data = req.body;         // Campos a actualizar

  const updatedActor = await actorService.updateActor(actorId, data);

  success(res, updatedActor, "Actor actualizado correctamente");
});

// Borrado de un registro usando el id
exports.deleteActor = asyncHandler(async (req, res) => {
  const actorId = req.params.id;

  const result = await actorService.deleteActor(actorId);

  success(res, result, "Actor eliminado exitosamente"); 
});


// obtencion de actores por rango de fechas
// GET /api/actor/fechas/:from/:to
// Ejemplo: http://localhost:3000/api/actor/fechas/2015-01-01/2030-01-01
// http://localhost:3000/api/actor/fechas/2010-12-01/2025-12-31
exports.getActorsByDateRange = asyncHandler(async (req, res) => {
  const { from, to } = req.params; // 'from' y 'to' son strings YYYY-MM-DD
  const rows = await actorService.getActorsByDateRange(from, to);
  success(res, rows, "Actores obtenidos por rango de fechas exitosamente");
});

// obtener de actores por rango de horas
// GET /api/actor/horas/:from/:to
//Ejempo http://localhost:3000/api/actor/horas/08:00:00/23:00:00
//http://localhost:3000/api/actor/horas/12:00:00/23:00:00

exports.getActorsByTimeRange = asyncHandler(async (req, res) => {
  const { from, to } = req.params; // 'from' y 'to' son strings HH:MM[:SS]
  const rows = await actorService.getActorsByTimeRange(from, to);
  success(res, rows, "Actores obtenidos por rango de horas exitosamente");
});


// Voy a obtener actores con nacionalidad = 'C' y salary entre 2Millomes  y 3Millones
//eJEMPLO: http://localhost:3000/api/actor/nacionalidad/salary

exports.getActorsByNationalityCAndSalaryRange = asyncHandler(async (req, res) => {
  const rows = await actorService.getActorsByNationalityCAndSalaryRange();
  success(res, rows,"Actores con nacionalidad 'C' y salario entre 2.000.000 y 3.000.000 obtenidos exitosamente"
  );
});