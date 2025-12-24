
//1. acceso a la base de datos
const pool= require("../config/db")

//2. Definicion de la funcion getAllFims
 exports.getAllFilms = async()=>{
    const query = "select * from film"
    const [rows] = await pool.execute(query)
    return rows
 } 


//3. getFilmById
exports.getFilmById = async(id)=>{
    const query= "select * from film where film_id=?"
    const [row] = await pool.execute(query, [id])
    return row[0]
}
