// Importamos Express para crear el router
const express = require("express");
const router = express.Router();

// Importamos el controller de mensajes privados
// El router solo define rutas, el controller maneja la lógica
const privateMessageController = require("../controllers/privateMessagesController");


// Obtiene todos los mensajes privados
router.get("/", privateMessageController.getAllPrivateMessages);


// Crea un nuevo mensaje privado
router.post("/", privateMessageController.createPrivateMessage);

// Exportamos el router
module.exports = router;
