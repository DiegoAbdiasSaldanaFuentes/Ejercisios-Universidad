// Importamos Express
const express = require("express");

// Creamos el router de Express
const router = express.Router();

// Importamos el controller de grupos
// Aquí se manejan las respuestas HTTP
const groupsController = require("../controllers/groupsController");

// Obtener todos los grupos
router.get("/", groupsController.getAllGroups);

// Crear grupos
router.post("/", groupsController.createGroup);

// Actualizar grupo (/groups/:id)
router.put("/:id", groupsController.updateGroup);

// Eliminar grupo (/groups/:id)
//router.delete("/:id", groupsController.deleteGroup);

// Exportamos el router para usarlo en app.js
module.exports = router;

