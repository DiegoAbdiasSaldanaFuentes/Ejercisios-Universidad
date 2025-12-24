//Vamos a capturar errores de funciones async
//con esto evitamos escribir en los controladores try/catch para el manejo de error
//



// src/middleware/asyncHandler.js
function asyncHandler(fn) {
  return (req, res, next) => {
    try {
      Promise.resolve(fn(req, res, next)).catch(next);
    } catch (err) {
      next(err);
    }
  };
}

module.exports = asyncHandler;