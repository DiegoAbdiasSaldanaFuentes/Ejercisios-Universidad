const readline = require("readline");

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question("Ingrese el primer número: ", (n1) => {
    rl.question("Ingrese el segundo número: ", (n2) => {
        n1 = parseInt(n1);
        n2 = parseInt(n2);

        if (n1 <= n2) {
            // recorrido ascendente
            for (let i = n1; i <= n2; i++) {
                if (i % 2 === 0) {
                    console.log("Es par:", i, '\n');
                } else {
                    console.log("Es impar:", i, '\n');
                }
            }
        } else {
            // recorrido descendente
            for (let i = n1; i >= n2; i--) {
                if (i % 2 === 0) {
                    console.log("Es par:", i, '\n');
                } else {
                    console.log("Es impar:", i, '\n');
                }
            }
        }

        rl.close();
    });
});
