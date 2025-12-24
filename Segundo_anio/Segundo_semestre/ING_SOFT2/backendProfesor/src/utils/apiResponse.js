
// src/utils/ApiResponse.js
/*class ApiResponse {
  static success(res, data, message = "Operación exitosa") {
    return res.status(200).json({
      success: true,
      message,
      data,
    });
  }
}

module.exports = ApiResponse;
*/


// src/utils/ApiResponse.js

// Respuesta estándar para peticiones exitosas
exports.success = function (res, data, message = "Operación exitosa") {
  return res.status(200).json({
    success: true,
    message,
    data,
  });
};

// (Opcional) otras respuestas comunes
exports.created = function (res, data, message = "Recurso creado exitosamente") {
  return res.status(201).json({
    success: true,
    message,
    data,
  });
};

exports.error = function (res, message = "Error en la operación", code = 500) {
  return res.status(code).json({
    success: false,
    message,
    data: null,
  });
};
