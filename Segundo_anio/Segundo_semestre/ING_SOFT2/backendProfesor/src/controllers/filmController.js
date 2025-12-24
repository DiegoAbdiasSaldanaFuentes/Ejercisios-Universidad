
const { success } = require("../utils/apiResponse");
const asyncHandler = require("../middleware/asyncHandler")
const filmModel = require("../models/filmModel")


exports.getAllFilms=  asyncHandler( async (req, res)=>{
    const rows = await filmModel.getAllFilms()
    success(res, rows, "Actores obtenidos exitosamente");
})

exports.getFilmById= asyncHandler( async(req, res)=>{
    const rows = await filmModel.getFilmById(req.params.id)
    success(res, rows, "Recuperación exitosa") 
})