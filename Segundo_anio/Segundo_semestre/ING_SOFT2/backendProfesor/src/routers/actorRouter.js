
const express=require('express')
const actorController= require('../controllers/actorController') 
const router=express.Router()


//consultas básicas
router.get("/",        actorController.getAllActors) 
router.get("/:id", actorController.getActorById)
router.post("/", actorController.saveActor)
router.put("/:id", actorController.updateActor);
router.delete("/:id", actorController.deleteActor);
router.get("/fechas/:from/:to", actorController.getActorsByDateRange);
router.get("/horas/:from/:to", actorController.getActorsByTimeRange);
router.get("/nacionalidad/salary", actorController.getActorsByNationalityCAndSalaryRange);

module.exports= router
