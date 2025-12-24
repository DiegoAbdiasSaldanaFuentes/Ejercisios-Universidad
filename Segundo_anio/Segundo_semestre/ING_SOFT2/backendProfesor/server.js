const express = require("express");
const  routers= require("./src/routers/index")
require("dotenv").config();
const path = require('path')

const PORT = process.env.PORT || 3000;

const server = express();

// Middleware para JSON
server.use(express.json());

// Usar routers
server.use("/", routers);

// Middleware para rutas no encontradas
server.use((req, res, next) => {
  res.status(404).json({
    error: true,
    message: `No se encontró la ruta ${req.originalUrl}`
  });
});

// Middleware global de errores
server.use((err, req, res, next) => {
//  const statusCode = err.statusCode || 500;
//  const statusType = statusCode >= 500 ? "error" : "fail";

  const statusCode = err.status || err.statusCode || 500; 
  const statusType = err.type >= 500 ? "error" : "fail";

  res.status(statusCode).json({
    status: statusType,
    message: err.message || "Ocurrió un error inesperado en el servidor.",
    code: statusCode,
    data: null
  });
});

// Cache control
server.use((req, res, next) => {
  res.setHeader("Cache-Control", "no-store");
  next();
});

// Arrancar servidor
server.listen(PORT, () => {
  console.log(`Servidor corriendo en puerto ${PORT}`);
});
 