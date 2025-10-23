function factorial(n) {
    if (n === 0 || n === 1) return 1; // caso base
    return n * factorial(n - 1);      // llamada recursiva
}

console.log(factorial(5)); // 120
