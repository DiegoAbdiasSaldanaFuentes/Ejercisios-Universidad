const express = require("express");
const app = express();

const routers = require("./src/routers/index");

app.use(express.json());

// Montamos TODAS las rutas
app.use("/", routers); // correcto si no quieres usar /api

// ============================
// Middleware global de errores
// ============================
app.use((err, req, res, next) => {
  console.error(err); // log para desarrollo
  res.status(err.status || 500).json({
    status: "error",
    message: err.message || "Error interno"
  });
});

const PORT = process.env.PORT || 3000;
app.listen(PORT, () => {
  console.log(`Servidor corriendo en http://localhost:${PORT}`);
});
