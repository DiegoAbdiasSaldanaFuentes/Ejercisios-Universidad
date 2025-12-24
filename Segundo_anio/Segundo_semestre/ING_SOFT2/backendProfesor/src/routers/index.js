


const actorRouter=require("./actorRouter")
const filmRouter= require("./filmRouter")

const express= require("express");
const routers= express.Router()

routers.use("/api/actor", actorRouter)
//routers.use("/api/film", filmRouter)


module.exports= routers
