
const express = require("express")
const filmController= require("../controllers/filmController")
const router = express.Router()
 

router.get("/"   , filmController.getAllFilms)
router.get("/:id", filmController.getFilmById)

module.exports= router 
