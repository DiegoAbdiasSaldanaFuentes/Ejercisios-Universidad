-- ========================================
-- Tabla usuarios
-- ========================================
CREATE TABLE usuarios (
  rut VARCHAR(12) PRIMARY KEY,
  nombre VARCHAR(100) NOT NULL,
  correo VARCHAR(120) UNIQUE NOT NULL,
  contrasena VARCHAR(200) NOT NULL,
  tipo_usuario ENUM('alumno', 'profesor', 'administrativo') NOT NULL,
  foto_perfil VARCHAR(300)
);

-- Insertar 20 usuarios
INSERT INTO usuarios (rut, nombre, correo, contrasena, tipo_usuario, foto_perfil) VALUES
('11111111-1','Administrador General','admin@saucm.cl','admin123','administrativo',NULL),
('22222222-2','Juan Pérez','juanp@saucm.cl','123','alumno',NULL),
('33333333-3','María López','marial@saucm.cl','123','alumno',NULL),
('44444444-4','Pedro Martínez','pedrom@saucm.cl','123','alumno',NULL),
('55555555-5','Ana Torres','anat@saucm.cl','123','alumno',NULL),
('66666666-6','Luis Ramírez','luisr@saucm.cl','123','profesor',NULL),
('77777777-7','Carla Fernández','carlaf@saucm.cl','123','profesor',NULL),
('88888888-8','Diego Silva','diegos@saucm.cl','123','profesor',NULL),
('99999999-9','Paula Herrera','paulah@saucm.cl','123','profesor',NULL),
('10101010-1','Jorge Rojas','jorger@saucm.cl','123','alumno',NULL),
('12121212-2','Valentina Castro','valec@saucm.cl','123','alumno',NULL),
('13131313-3','Fernando Soto','fernandos@saucm.cl','123','alumno',NULL),
('14141414-4','Camila Vega','camilav@saucm.cl','123','alumno',NULL),
('15151515-5','Ignacio Fuentes','ignaciof@saucm.cl','123','alumno',NULL),
('16161616-6','Daniela Ríos','danielar@saucm.cl','123','alumno',NULL),
('17171717-7','Andrés Molina','andresm@saucm.cl','123','alumno',NULL),
('18181818-8','Sofía Muñoz','sofiam@saucm.cl','123','alumno',NULL),
('19191919-9','Cristian Valdés','cristianv@saucm.cl','123','alumno',NULL),
('20202020-2','Lorena Aguirre','lorenaa@saucm.cl','123','profesor',NULL),
('21212121-1','Patricio Orellana','patricioo@saucm.cl','123','administrativo',NULL);

-- ========================================
-- Tabla grupos
-- ========================================
CREATE TABLE grupos (
  id INT AUTO_INCREMENT PRIMARY KEY,
  nombre VARCHAR(100) NOT NULL,
  descripcion TEXT,
  creador_rut VARCHAR(12) NOT NULL,
  privado BOOLEAN DEFAULT 0,
  FOREIGN KEY (creador_rut) REFERENCES usuarios(rut)
);

-- Insertar 2 grupos
INSERT INTO grupos (nombre, descripcion, creador_rut, privado) VALUES
('General', 'Grupo principal de la plataforma', '11111111-1', 0),
('Proyecto X', 'Grupo para proyectos especiales', '66666666-6', 1);

ALTER TABLE grupos ADD COLUMN etiqueta VARCHAR(50) DEFAULT 'general';

-- ========================================
-- Tabla msj_grupos
-- ========================================
CREATE TABLE msj_grupos (
  id INT AUTO_INCREMENT PRIMARY KEY,
  id_grupo INT NOT NULL,
  emisor_rut VARCHAR(12) NOT NULL,
  contenido TEXT NOT NULL,
  FOREIGN KEY (id_grupo) REFERENCES grupos(id),
  FOREIGN KEY (emisor_rut) REFERENCES usuarios(rut)
);

-- Mensajes en grupos
INSERT INTO msj_grupos (id_grupo, emisor_rut, contenido) VALUES
(1, '22222222-2', 'Hola a todos!'),
(1, '33333333-3', 'Bienvenidos al grupo General.'),
(2, '66666666-6', 'Revisen los avances del proyecto X.'),
(2, '77777777-7', 'Tengo algunas dudas sobre la tarea.');

-- ========================================
-- Tabla msj_privados
-- ========================================
CREATE TABLE msj_privados (
  id INT AUTO_INCREMENT PRIMARY KEY,
  emisor_rut VARCHAR(12) NOT NULL,
  receptor_rut VARCHAR(12) NOT NULL,
  contenido TEXT NOT NULL,
  FOREIGN KEY (emisor_rut) REFERENCES usuarios(rut),
  FOREIGN KEY (receptor_rut) REFERENCES usuarios(rut)
);

-- ========================================
-- Tabla archivos
-- ========================================
CREATE TABLE archivos (
  id INT AUTO_INCREMENT PRIMARY KEY,
  dueno_rut VARCHAR(12) NOT NULL,
  nombre VARCHAR(150) NOT NULL,
  ruta VARCHAR(300) NOT NULL,
  descripcion TEXT,
  FOREIGN KEY (dueno_rut) REFERENCES usuarios(rut)
);

-- Archivos: 1 mínimo por usuario
INSERT INTO archivos (dueno_rut, nombre, ruta, descripcion) VALUES
('22222222-2','Archivo Juan','/archivos/juan1.pdf','Primer archivo de Juan'),
('33333333-3','Archivo María','/archivos/maria1.pdf','Primer archivo de María'),
('44444444-4','Archivo Pedro','/archivos/pedro1.pdf','Primer archivo de Pedro'),
('55555555-5','Archivo Ana','/archivos/ana1.pdf','Primer archivo de Ana'),
('66666666-6','Archivo Luis','/archivos/luis1.pdf','Archivo del profesor Luis'),
('77777777-7','Archivo Carla','/archivos/carla1.pdf','Archivo del profesor Carla'),
('88888888-8','Archivo Diego','/archivos/diego1.pdf','Archivo del profesor Diego'),
('99999999-9','Archivo Paula','/archivos/paula1.pdf','Archivo del profesor Paula'),
('10101010-1','Archivo Jorge','/archivos/jorge1.pdf','Archivo de Jorge'),
('12121212-2','Archivo Valentina','/archivos/valentina1.pdf','Archivo de Valentina'),
('13131313-3','Archivo Fernando','/archivos/fernando1.pdf','Archivo de Fernando'),
('14141414-4','Archivo Camila','/archivos/camila1.pdf','Archivo de Camila'),
('15151515-5','Archivo Ignacio','/archivos/ignacio1.pdf','Archivo de Ignacio'),
('16161616-6','Archivo Daniela','/archivos/daniela1.pdf','Archivo de Daniela'),
('17171717-7','Archivo Andrés','/archivos/andres1.pdf','Archivo de Andrés'),
('18181818-8','Archivo Sofía','/archivos/sofia1.pdf','Archivo de Sofía'),
('19191919-9','Archivo Cristian','/archivos/cristian1.pdf','Archivo de Cristian'),
('20202020-2','Archivo Lorena','/archivos/lorena1.pdf','Archivo de Lorena'),
('21212121-1','Archivo Patricio','/archivos/patricio1.pdf','Archivo de Patricio');

ALTER TABLE archivos ADD COLUMN etiqueta VARCHAR(50) DEFAULT 'general';


-- ========================================
-- Tabla comentarios_archivos
-- ========================================
CREATE TABLE comentarios_archivos (
  id INT AUTO_INCREMENT PRIMARY KEY,
  archivo_id INT NOT NULL,
  autor_rut VARCHAR(12) NOT NULL,
  contenido TEXT NOT NULL,
  FOREIGN KEY (archivo_id) REFERENCES archivos(id),
  FOREIGN KEY (autor_rut) REFERENCES usuarios(rut)
);

-- Comentarios en archivos (10)
INSERT INTO comentarios_archivos (archivo_id, autor_rut, contenido) VALUES
(1,'33333333-3','Buen trabajo Juan.'),
(2,'22222222-2','Gracias María!'),
(3,'44444444-4','Revisado Pedro.'),
(4,'55555555-5','Bien Ana.'),
(5,'66666666-6','Archivo recibido.'),
(6,'77777777-7','Comentario sobre Carla.'),
(7,'88888888-8','Comentario Diego.'),
(8,'99999999-9','Comentario Paula.'),
(9,'10101010-1','Comentario Jorge.'),
(10,'12121212-2','Comentario Valentina.');

-- ========================================
-- Tabla advertencias
-- ========================================
CREATE TABLE advertencias (
  id INT AUTO_INCREMENT PRIMARY KEY,
  usuario_rut VARCHAR(12) NOT NULL,
  admin_rut VARCHAR(12) NOT NULL,
  motivo TEXT NOT NULL,
  FOREIGN KEY (usuario_rut) REFERENCES usuarios(rut),
  FOREIGN KEY (admin_rut) REFERENCES usuarios(rut)
);

-- Advertencia de ejemplo
INSERT INTO advertencias (usuario_rut, admin_rut, motivo) VALUES
('22222222-2','11111111-1','Archivo inapropiado');