/*Codigo por Diego Saldania*/

/*Usando el formate de buenas practicas*/
CREATE TABLE TABLA_DS_CLIENTES(
    NUMERO_CLIENTES  NUMBER,
    NOMBRE_CLIENTES VARCHAR(50),
    APELLIDO1_CLIENTES VARCHAR(30),
    APELLIDO2_CLIENTES VARCHAR(30),
    DIRECCION_CLIENTES VARCHAR(80),
    SALDO NUMBER,
    CREDITO NUMBER,
    DESCUENTO NUMBER,
    CONSTRAINT PK_DS_NUMERO_CLIENTES PRIMARY KEY(NUMERO_CLIENTES)
);

--INSERTAR DATOS--
/*INSERT INTO TABLA_DS_CLIENTES(NUMERO_CLIENTES, NOMBRE_CLIENTES, APELLIDO1_CLIENTES, APELLIDO2_CLIENTES, DIRECCION_CLIENTES, SALDO, CREDITO, DESCUENTO)
    VALUES (1, 'carlos', 'castro', 'bustamante', 'talca', 500, 5000, 20);

INSERT INTO TABLA_DS_CLIENTES(NUMERO_CLIENTES, NOMBRE_CLIENTES, APELLIDO1_CLIENTES, APELLIDO2_CLIENTES, DIRECCION_CLIENTES, SALDO, CREDITO, DESCUENTO)
    VALUES (2, 'alicia', 'sanhueza', 'bravo', 'villa alegre', 600, 2000, 40);

INSERT INTO TABLA_DS_CLIENTES(NUMERO_CLIENTES, NOMBRE_CLIENTES, APELLIDO1_CLIENTES, APELLIDO2_CLIENTES, DIRECCION_CLIENTES, SALDO, CREDITO, DESCUENTO)
    VALUES (3, 'pedro', 'bravo', 'nuñez', 'linares', 10000, 1000, 60);
*/

-- modificar dentro de las tablas UPDATE--
/*
UPDATE TABLA_DS_CLIENTES SET 
    APELLIDO2_CLIENTES = 'SOTO',
    WHERE(NUMERO_CLIENTES = 3);
*/




--MOSTRAR TODO LO QUE HAYA EN TABLA CLINETES--
/*
SELECT FROM TABLA_DS_CLIENTES
    WHERE(APELLIDO1_CLIENTES=1)
*/

--FILTRAR POR DESCUENTO--
/* SELECT NUMERO_CLIENTES, NOMBRE_CLIENTES, APELLIDO1_CLIENTES, APELLIDO2_CLIENTES
    FROM TABLA_DS_CLIENTES
    WHERE(DESCUENTO > 20)
        */