

CREATE TABLE PRODUCTOS(
    codigoproducto VARCHAR(100) PRIMARY KEY,
    nombre VARCHAR(50),
    precio DECIMAL,
    categoria VARCHAR(100)
);
INSERT INTO PRODUCTOS (nombre, precio) VALUES ('Notebook Lenovo', 380000);
INSERT INTO PRODUCTOS (nombre, precio) VALUES ('Celular Motorola', 110000);
INSERT INTO PRODUCTOS (nombre, precio) VALUES ('Audifonos', 3500);
SELECT nombre, precio FROM PRODUCTOS WHERE precio<100000;