-- Esta es mi primera base de dato
-- by Diego Saldania
CREATE DATABASE MinuevaBD; -- Crea la base de datos

USE MinuevaBD; -- Activa la DB para trabajar con ella

CREATE TABLE Usuarios(
	ID INT PRIMARY KEY IDENTITY,
	Nombre VARCHAR(50),
	Correo VARCHAR(100)
);

--Insersion de datos
INSERT INTO Usuarios(Nombre,Correo)
	VALUES('Diego','diego.saldana@alumnos.ucm.cl');

--Consuta de datos
SELECT *FROM Usuarios;