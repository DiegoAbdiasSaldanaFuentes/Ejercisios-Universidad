let numeros = [1, 2, 3, 4, 5];

// map
let cuadrados = numeros.map(n => n * n);
console.log(cuadrados);

// filter
let pares = numeros.filter(n => n % 2 === 0);
console.log(pares);

// reduce
let suma = numeros.reduce((acc, n) => acc + n, 0);
console.log(suma);
