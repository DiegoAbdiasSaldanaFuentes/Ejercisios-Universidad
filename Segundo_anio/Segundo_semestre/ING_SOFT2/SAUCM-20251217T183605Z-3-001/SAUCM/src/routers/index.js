// Importamos el pool de conexión a MySQL
const pool = require("../config/db");

// Importamos Express
const express = require("express");

// Creamos el router principal
const routers = express.Router();

// Importación de routers específicos
const usersRouter = require("./usersRouter");
const groupsRouter = require("./groupsRouter");
const privateMessagesRouter = require("./privateMessagesRouter");
const groupMessagesRouter = require("./groupMessagesRouter.js");
const filesRouter = require("./filesRouter");

// Ruta de prueba para verificar conexión a la BD
routers.get("/test-db", async (req, res) => {
  try {
    const [rows] = await pool.query("SELECT * FROM usuarios");
    res.json({
      status: "success",
      data: rows
    });
  } catch (err) {
    res.status(500).json({
      status: "error",
      message: err.message
    });
  }
});

// Usuarios
routers.use("/users", usersRouter);

// Grupos
routers.use("/groups", groupsRouter);

// Mensajes privados
routers.use("/messages/private", privateMessagesRouter);

// Mensajes grupales
routers.use("/messages/group", groupMessagesRouter);

routers.use("/files", filesRouter);

// Exportamos el router principal
module.exports = routers;

