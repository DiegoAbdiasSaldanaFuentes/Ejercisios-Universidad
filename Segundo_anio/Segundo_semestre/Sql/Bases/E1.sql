--Tienes una tabla llamada Videojuegos con las siguientes columnas:
--ID (int)
--Titulo (varchar)
--Desarrolladora (varchar)
--Precio (decimal)
--Fecha_Lanzamiento (date)


CREATE TABLE VIDEOJUEGOS(
    ID INT PRIMARY KEY,
    TITULO VARCHAR(100),
    DESARROLLADORA VARCHAR(100),
    PRECIO DECIMAL,
    FECHA_LANZAMIENTO DATETIME
);

SELECT TITULO, DESARROLLADORA FROM VIDEOJUEGOS;


