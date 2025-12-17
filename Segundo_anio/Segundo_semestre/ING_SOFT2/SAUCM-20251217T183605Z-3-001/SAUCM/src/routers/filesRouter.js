// Importamos Express
const express = require("express");

// Creamos el router de Express
const router = express.Router();

// Importamos el controller de archivos
// Aquí se manejan las respuestas HTTP
const filesController = require("../controllers/filesController");

// ======================================
// GET /api/files
// Obtiene todos los archivos
// ======================================
router.get("/", filesController.getAllFiles);

// ======================================
// POST /api/files
// Crea un nuevo archivo
// ======================================
router.post("/", filesController.createFile);

// Exportamos el router para usarlo en app.js
module.exports = router;

