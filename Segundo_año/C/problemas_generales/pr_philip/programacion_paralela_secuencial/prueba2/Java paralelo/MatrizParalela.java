/*************************************************************************
 * -Nombre autor: Diego Saldaña
 *- Nombre docente: Francisco Philip Vásquez Iglesias
 * -Nombre del proyecto: Multiplicación de matrices
 * -Problema planteado: Implementar un programa en Java utilizando paralelismo 
 * que realice la multiplicacion de 2 matrices cuadradas grandes
 * -Fecha comienzo: 06-07-2025
 * -Fecha Finalización: 07-07-2025                                                   
 *                                                                                                                                         *
 *************************************************************************/
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.concurrent.*;

public class MatrizParalela {
    static final int TAM = 5000;
    static final int NUM_THREADS = 20;

    static int[][] matris1 = new int[TAM][TAM];
    static int[][] matris2 = new int[TAM][TAM];
    static int[][] resultado = new int[TAM][TAM];

    public static void main(String[] args) throws Exception {
        // Inicializar matrices
        int num = 0;
        for (int i = 0; i < TAM; i++) {
            for (int j = 0; j < TAM; j++) {
                matris1[i][j] = num;
                matris2[i][j] = num;
                resultado[i][j] = 0;
                num++;
            }
        }

        ExecutorService pool = Executors.newFixedThreadPool(NUM_THREADS);

        long tiempoInicio = System.nanoTime();

        // Dividir el trabajo por filas
        for (int i = 0; i < TAM; i++) {
            final int fila = i;
            pool.submit(() -> {
                for (int j = 0; j < TAM; j++) {
                    int suma = 0;
                    for (int k = 0; k < TAM; k++) {
                        suma += matris1[fila][k] * matris2[k][j];
                    }
                    resultado[fila][j] = suma;
                }
            });
        }

        pool.shutdown();
        pool.awaitTermination(1, TimeUnit.HOURS);

        long tiempoFin = System.nanoTime();
        double tiempoTotal = (tiempoFin - tiempoInicio) / 1e9;

        // Guardar resultado
        try (PrintWriter out = new PrintWriter(new FileWriter("resultado_multiplicacion.txt"))) {
            for (int i = 0; i < TAM; i++) {
                for (int j = 0; j < TAM; j++) {
                    out.print(resultado[i][j] + " ");
                }
                out.println();
            }
        }

        System.out.println("\nVersión paralela de la multiplicación de matrices (Java)");
        System.out.printf("fila y columna %dx%d\n", TAM, TAM);
        System.out.printf("cantidad de hilos usados: %d\n", NUM_THREADS);
        System.out.printf("tiempo total: %.4f segundos\n", tiempoTotal);
    }
}
