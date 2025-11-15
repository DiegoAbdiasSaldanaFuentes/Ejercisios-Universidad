
const usuarios = new Map();

usuarios.set("Usuario1",{nombre : "Diego",nivel: 10,sigma:"No"},);
usuarios.set("Usuario2",{nombre : "Victor",nivel: 10,sigma:"Si"});

for(let[clave, valor] of usuarios ){
    console.log(clave, valor);
};