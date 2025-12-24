const pool = require("../config/db");

// CRUD sobre la tabla actor

//Recupera todos los actores
exports.getAllActors = async () => {
   const query= "SELECT * FROM actor"
   const [rows] = await pool.execute(query);
   return rows;
};

//Recupera un actor por un id
exports.getActorById= async(id)=>{
  const query= "select * from actor where actor_id= ?"
  const [rows]= await pool.execute(query, [id]) 
  return rows[0]
}

//Graba el registro en la tabla actor
exports.saveActor = async (data) => {
  // data viene de req.body, 

  const nameColumns = Object.keys(data).join(",");               // "first_name,last_name"
  const placeholders = Object.keys(data).map(() => "?").join(","); // "?,?"
  const values = Object.values(data);                            // ["ANA", "TORANZO"]
  const query = `INSERT INTO actor (${nameColumns}) VALUES (${placeholders})`;
  const [result] = await pool.execute(query, values);
  return { actor_id: result.insertId, ...data };
};




// Actualizar un actor por id (UPDATE dinámico)
exports.updateActor = async (id, data) => {
  const fields = Object.keys(data);

  if (fields.length === 0) {
    // Nada que actualizar
    return 0;
  }


  // Construimos: "first_name = ?, last_name = ?"
  const setClause = fields.map(field => `${field} = ?`).join(", ");
  const values = fields.map(field => data[field]);

  const query = `UPDATE actor SET ${setClause} WHERE actor_id = ?`;

  const [result] = await pool.execute(query, [...values, id]);

  // affectedRows indica cuántos registros se actualizaron
  return result.affectedRows;
};


// Borrar un actor por id
exports.deleteActor = async (id) => {
  const query = "DELETE FROM actor WHERE actor_id = ?";
  const [result] = await pool.execute(query, [id]);

  return result.affectedRows;
};


// actores por rango de horas
exports.getActorsByDateRange = async (from, to) => {
  const query = `
    SELECT *
    FROM actor
    WHERE dateBegin IS NOT NULL
      AND dateEnd   IS NOT NULL
      AND dateBegin >= ?
      AND dateEnd   <= ?
  `;

  const [rows] = await pool.execute(query, [from, to]);
  return rows;
};

// actores por rango de horas
exports.getActorsByTimeRange = async (from, to) => {
  const query = `
    SELECT *
    FROM actor
    WHERE horaBegin IS NOT NULL
      AND horaEnd   IS NOT NULL
      AND horaBegin >= ?
      AND horaEnd   <= ?
  `;

  const [rows] = await pool.execute(query, [from, to]);
  return rows;
};




//Buscar en la tabla actorpor  nacionalidad = 'C' y salary entre 2.000.000 y 3.000.000
exports.getActorsByNationalityCAndSalaryRange = async () => {
  const query = `
    SELECT *
    FROM actor
    WHERE nacionalidad = 'C'
      AND salary BETWEEN 2000000 AND 3000000
  `;

  const [rows] = await pool.execute(query);
  return rows;
};



















 


/*
exports.saveActor= async(data)=>{
  const nameColums = Object.keys(data).join(",")
  const simbolos = data.map(()=>"?").join(",")
  const valuesColumns = Object.values(data)
  const query = `insert into actor  (${nameColumns})  value (${simbolos})`
  const [result] = await pool.execute(query, valueColumns)
  return { actor_id: rows.insertId, ...data};
}
*/
/*
exports.getActorById = async (id) => {
    const query = "SELECT * FROM actor WHERE actor_id = ?" 
    const [rows] = await pool.execute(query, [id]);
    return rows[0];
};
*/
/*
exports.createActor = async (first_name, last_name) => {
  const query    = "INSERT INTO actor (first_name, last_name) VALUES (?, ?)"  
  const [rows] = await pool.execute(query,[first_name, last_name]);
  return { actor_id: rows.insertId, first_name, last_name };
};

exports.updateActor = async (id, first_name, last_name) => {
  await pool.execute(
    "UPDATE actor SET first_name = ?, last_name = ? WHERE actor_id = ?",
    [first_name, last_name, id]
  );
};

exports.deleteActor = async (id) => {
  await pool.execute("DELETE FROM actor WHERE actor_id = ?", [id]);
};

// Consulta con JOIN: obtener actor con sus películas
exports.getActorsWithFilms = async (titleFilter = "") => {
  const [rows] = await pool.execute(`
    SELECT 
      A.actor_id,
      CONCAT(A.first_name, ' ', A.last_name) AS full_name_actor,
      F.title AS film_title,
      F.description AS film_description,
      F.release_year AS film_release_year
    FROM actor A
    LEFT JOIN film_actor FA ON A.actor_id = FA.actor_id
    LEFT JOIN film F ON FA.film_id = F.film_id
    WHERE F.title LIKE ?
    ORDER BY full_name_actor, film_title
  `, [`%${titleFilter}%`]);
  return rows;
};
*/