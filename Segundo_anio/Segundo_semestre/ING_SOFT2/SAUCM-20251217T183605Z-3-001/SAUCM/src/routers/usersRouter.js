// Importamos Express
const express = require("express");

// Creamos el router de Express
const router = express.Router();

// Importamos el controller de usuarios
// Aquí se manejan las respuestas HTTP
const usersController = require("../controllers/usersController");

// Obtener todos los usuarios
router.get("/", usersController.getAllUsers);

// Crear usuario
router.post("/", usersController.createUser);

// Editar usuario
router.put("/:rut", usersController.updateUser);

module.exports = router;
