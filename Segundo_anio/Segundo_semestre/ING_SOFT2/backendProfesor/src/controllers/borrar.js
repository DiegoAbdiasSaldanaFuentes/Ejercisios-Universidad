
Mis explicaciones del codigo esta numerada
1. mi archivo actorRouter.js Tiene:
const express=require('express')
const actorController= require('../controllers/actorController') 
const router=express.Router()


//consultas básicas
router.get("/",        actorController.getAllActors) 
router.get("/:id", actorController.getActorById)
router.post("/", actorController.saveActor)
router.put("/:id", actorController.updateActor);
router.delete("/:id", actorController.deleteActor);

module.exports= router




2. mi archivo actorController.js Tiene


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


//Borrado de un registro usando el id 
// Eliminar un actor por ID
exports.deleteActor = asyncHandler(async (req, res) => {
  // Llama al servicio (que valida ID y lanza errores si algo va mal)

  const row = await actorService.getActorById(req.params.id)
  success(res, row, "Registro Eliminado exitosamente")

  /*
    const result = await actorService.deleteActor(req.params.id);
     console.log("actorController "+result)
    // Si llega aquí, es porque se eliminó correctamente
    success(res, result, "Actor eliminado correctamente");
  */
});





//Grbando un actor en la tabla. 
exports.saveActor = asyncHandler(async (req, res) => {
  const nuevoActor = await actorService.saveActor(req.body);
  success(res, nuevoActor, "Actor creado exitosamente");
});


 3. Mi archivo actorService.js tiene:

const actorModel = require("../models/actorModel")
const errorMap = require("../utils/errorMap");

//Recuoerando todos los registros de actores
exports.getAllActors= async()=>{
    return await actorModel.getAllActors()
}



// recuperando a traves del id. 
// VALIDANDO SI 
exports.getActorById = async (idParam) => {
  // Validación: ID debe ser entero
  if (!/^\d+$/.test(idParam)) {
    const error = new Error(errorMap.BAD_REQUEST.message);
    error.statusCode = errorMap.BAD_REQUEST.status;
    error.type = errorMap.BAD_REQUEST.type;
    throw error;
  }

  const id = parseInt(idParam, 10);
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



 4. Mi archivo actorModel.js tiene:
 const pool = require("../config/db");

// CRUD sobre la tabla actor

//Recupera todos los actores
exports.getAllActors = async () => {
   const query= "SELECT * FROM actor"
   const [rows] = await pool.execute(query);
   return rows;
};

//Recupera un actor por un id
exports.getActorById= async(id)=>{
  const query= "select * from actor where actor_id= ?"
  const [rows]= await pool.execute(query, [id]) 
  return rows[0]
}

//Graba el registro en la tabla actor
exports.saveActor = async (data) => {
  // data viene de req.body, por ejemplo: { first_name: "ANA", last_name: "TORANZO" }

  const nameColumns = Object.keys(data).join(",");               // "first_name,last_name"
  const placeholders = Object.keys(data).map(() => "?").join(","); // "?,?"
  const values = Object.values(data);                            // ["ANA", "TORANZO"]

  const query = `INSERT INTO actor (${nameColumns}) VALUES (${placeholders})`;

  const [result] = await pool.execute(query, values);

  return { actor_id: result.insertId, ...data };
};



5. Quiero las funciones para actualizar y borrar registro usando la estrucura de archivo. Las las funciones del actorController llaman a la funcion sucess. Por tanto, usa solamente  la funcion "sucess" en el actorController



como puede recuperar del siguiente objeto, llamado rows, el atributo sucess?
rows={
  "success": true,
  "message": "Actores obtenidos exitosamente",
  "data": [
    {
      "actor_id": 1,
      "first_name": "PENELOPE1",
      "last_name": "GUINESS1",
      "last_update": "2025-12-04T14:33:17.000Z"
    },
    {
      "actor_id": 2,
      "first_name": "NICK",
      "last_name": "WAHLBERG",
      "last_update": "2006-02-15T07:34:33.000Z"
    },
    {
      "actor_id": 3,
      "first_name": "ED",
      "last_name": "CHASE",
      "last_update": "2006-02-15T07:34:33.000Z"
    },
    {
      "actor_id": 4,
      "first_name": "JENNIFER",
      "last_name": "DAVIS",
      "last_update": "2006-02-15T07:34:33.000Z"
    }
  ]
}




en la siguiente tabla actor de MYSQL agrega lo siguiente:
dateBegin de tipo DATE
dateEnd de tipo DATE
isProfesional     de tipo Boolean
salary                de tipo int
horaBegin de tipo time
horaEnd de tipo   time




DROP TABLE IF EXISTS `actor`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `actor` (
  `actor_id` smallint unsigned NOT NULL AUTO_INCREMENT,
  `first_name` varchar(45) NOT NULL,
  `last_name` varchar(45) NOT NULL,
  `last_update` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`actor_id`),
  KEY `idx_actor_last_name` (`last_name`)
) ENGINE=InnoDB AUTO_INCREMENT=201 DEFAULT CHARSET=utf8mb3;





DROP TABLE IF EXISTS `actor`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;

CREATE TABLE `actor` (
  `actor_id` SMALLINT UNSIGNED NOT NULL AUTO_INCREMENT,
  `first_name` VARCHAR(45) NOT NULL,
  `last_name` VARCHAR(45) NOT NULL,
  `last_update` TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,

  -- Nuevos campos solicitados
  `dateBegin` DATE NULL,
  `dateEnd` DATE NULL,
  `isProfesional` BOOLEAN DEFAULT 0,   -- BOOLEAN = TINYINT(1)
  `salary` INT NULL,
  `horaBegin` TIME NULL,
  `horaEnd` TIME NULL,

  PRIMARY KEY (`actor_id`),
  KEY `idx_actor_last_name` (`last_name`)
) ENGINE=InnoDB AUTO_INCREMENT=201 DEFAULT CHARSET=utf8mb3;

La tabla actor tiene 204 registros. Agregar datos aleatorios a los campos de mas abajo. Las restricciones sobre los datos a generar en forma aleatoria son:
el campo dateEnd es de 5 a 15 anos mayor dateBegin 
el campo   salary es un valor entero entre 1200000 y 7000000
el campo horaEnd es de 5 a 15 horas mayor horaBegin 
el campo  isProfesional es campo tiene los valores 0 o 1

`dateBegin` DATE NULL,
  `dateEnd` DATE NULL,
  `isProfesional` BOOLEAN DEFAULT 0,   -- BOOLEAN = TINYINT(1)
  `salary` INT NULL,
  `horaBegin` TIME NULL,
  `horaEnd` TIME NULL,


aplico GET en http://localhost:3000/api/actor/1

{
  "status": "fail",
  "message": "rows is not defined",
  "code": 500,
  "data": null
}







    {

      "first_name": "PENELOPE1...",
      "last_name": "GUINESS1..",
      "dateBegin": "2025-10-24T03:00:00.000Z",
      "dateEnd": "2025-10-24T03:00:00.000Z",
      "isProfesional": 1,
      "salary": 5000000,
      "horaBegin": "15:00:00",
      "horaEnd": "23:00:00"
    }
    





    uso put con http://localhost:3000/api/actor/1
    y envio el siguiente json.  


    {

      "first_name": "JosemariaPENELOPE1...",
      "last_name": "Josemaria GUINESS1..",
      "dateBegin": "2030-12-30",
      "dateEnd": "2030-12-30",
      "isProfesional": 1,
      "salary": 3000000,
      "horaBegin": "03:00:00",
      "horaEnd": "23:30:00"
    }
    
 Sin embargo, thinder client dateBegin y dateEnd con un "T". Sin embargo, a lista la tabla actor con select * from actor no aparece la "T" con todo lo que le sigue
    "dateBegin": "2030-12-30T03:00:00.000Z",
    "dateEnd": "2030-12-30T03:00:00.000Z",

{
  "success": true,
  "message": "Actor actualizado correctamente",
  "data": {
    "actor_id": 1,
    "first_name": "JosemariaPENELOPE1...",
    "last_name": "Josemaria GUINESS1..",
    "last_update": "2025-12-04T19:47:23.000Z",
    "dateBegin": "2030-12-30T03:00:00.000Z",
    "dateEnd": "2030-12-30T03:00:00.000Z",
    "isProfesional": 1,
    "salary": 3000000,
    "horaBegin": "03:00:00",
    "horaEnd": "23:30:00"
  }
}





    http://localhost:3000/api/actor/1


    ALTER TABLE actor
ADD COLUMN nacionalidad CHAR(1) 
  NOT NULL 
  DEFAULT 'C'
  CHECK (nacionalidad IN ('C','E'));



    ALTER TABLE actor
ADD COLUMN genero CHAR(1) 
  NOT NULL 
  DEFAULT 'C'
  CHECK (nacionalidad IN ('C','E'));
