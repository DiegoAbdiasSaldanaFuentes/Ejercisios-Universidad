

const errorMap = {
    // 1. Errores de Base de Datos (MySQL, PostgreSQL, etc.)
    ER_ACCESS_DENIED_ERROR: {
        status: 401,
        type: "fail",
        message: "Credenciales de base de datos inválidas.",
    },
    ER_BAD_DB_ERROR: {
        status: 500,
        type: "error",
        message: "La base de datos solicitada no existe.",
    },
    ER_CON_COUNT_ERROR: {
        status: 503,
        type: "error",
        message: "Demasiadas conexiones activas a la base de datos.",
    },
    PROTOCOL_CONNECTION_LOST: {
        status: 503,
        type: "error",
        message: "Conexión con la base de datos perdida.",
    },
    ECONNREFUSED: {
        status: 503,
        type: "error",
        message: "La base de datos no responde (servidor apagado o inaccesible).",
    },
    ETIMEDOUT: {
        status: 504,
        type: "error",
        message: "Tiempo de espera agotado al conectar con la base de datos.",
    },

    // 2. Errores de Red / Internet
    ENOTFOUND: {
        status: 503,
        type: "error",
        message: "No se pudo resolver la dirección del host remoto (DNS).",
    },
    EAI_AGAIN: {
        status: 503,
        type: "error",
        message: "Fallo temporal de DNS. Intente nuevamente.",
    },
    ECONNRESET: {
        status: 502,
        type: "error",
        message: "Conexión de red reiniciada abruptamente.",
    },
    ENETUNREACH: {
        status: 503,
        type: "error",
        message: "La red no está disponible. Verifique conexión a internet.",
    },
    EHOSTUNREACH: {
        status: 503,
        type: "error",
        message: "No se puede acceder al host remoto.",
    },

    
    // 3. Errores de Servidor / Infraestructura
        EADDRINUSE: {
        status: 500,
        type: "error",
        message: "El puerto del backend ya está en uso.",
    },
    EPIPE: {
        status: 500,
        type: "error",
        message: "Error de escritura en un socket roto.",
    },
    ENOSPC: {
        status: 507,
        type: "error",
        message: "El servidor no tiene espacio en disco disponible.",
    },
    EROFS: {
        status: 500,
        type: "error",
        message: "Intento de escritura en un sistema de solo lectura.",
    },
    EMFILE: {
        status: 500,
        type: "error",
        message: "Demasiados archivos abiertos simultáneamente en el servidor.",
    },

     
    // 4. Errores de Cliente HTTP hacia el Backend
    BAD_REQUEST: {
        status: 400,
        type: "fail",
        message: "Solicitud inválida. Revise los parámetros enviados.",
    },
    UNAUTHORIZED: {
        status: 401,
        type: "fail",
        message: "Acceso no autorizado. Se requieren credenciales válidas.",
    },
    FORBIDDEN: {
        status: 403,
        type: "fail",
        message: "Acceso prohibido al recurso solicitado.",
    },
    NOT_FOUND: {
        status: 404,
        type: "fail",
        message: "El recurso solicitado no existe.",
    },
    PAYLOAD_TOO_LARGE: {
        status: 413,
        type: "fail",
        message: "El tamaño del cuerpo de la solicitud excede el límite permitido.",
    },


    // 5. Errores Genéricos de Backend
    INTERNAL_SERVER_ERROR: {
        status: 500,
        type: "error",
        message: "Ocurrió un error inesperado en el servidor.",
    },
    SERVICE_UNAVAILABLE: {
        status: 503,
        type: "error",
        message: "Servicio temporalmente no disponible.",
    },
    GATEWAY_TIMEOUT: {
        status: 504,
        type: "error",
        message: "Tiempo de espera agotado en el servidor.",
    },
};

module.exports = errorMap;


 