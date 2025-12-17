
// Importamos Express
const express = require("express");

// Creamos el router de Express
const router = express.Router();

// Importamos el controller de mensajes de grupos
// Aquí se manejan las respuestas HTTP
const groupMessagesController = require("../controllers/messagesController");

// Obtiene todos los mensajes de grupos
router.get("/", groupMessagesController.getAllGroupMessages);


// Crea un mensaje en un grupo
router.post("/", groupMessagesController.createGroupMessage);

module.exports = router;
