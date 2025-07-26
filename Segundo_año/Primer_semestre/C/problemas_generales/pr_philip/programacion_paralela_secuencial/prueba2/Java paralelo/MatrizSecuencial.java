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

public class MatrizSecuencial {
    static final int TAM = 5000;

    public static void main(String[] args) throws Exception {
        int[][] matris1 = new int[TAM][TAM];
        int[][] matris2 = new int[TAM][TAM];
        int[][] resultado = new int[TAM][TAM];

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

        long tiempoInicio = System.nanoTime();

        // Multiplicación secuencial
        for (int i = 0; i < TAM; i++) {
            for (int j = 0; j < TAM; j++) {
                int suma = 0;
                for (int k = 0; k < TAM; k++) {
                    suma += matris1[i][k] * matris2[k][j];
                }
                resultado[i][j] = suma;
            }
        }

        long tiempoFin = System.nanoTime();
        double tiempoTotal = (tiempoFin - tiempoInicio) / 1e9;

        // Guardar resultado
        try (PrintWriter out = new PrintWriter(new FileWriter("resultado_multiplicacion_secuencial.txt"))) {
            for (int i = 0; i < TAM; i++) {
                for (int j = 0; j < TAM; j++) {
                    out.print(resultado[i][j] + " ");
                }
                out.println();
            }
        }

        System.out.println("\nVersión secuencial de la multiplicación de matrices (Java)");
        System.out.printf("fila y columna %dx%d\n", TAM, TAM);
        System.out.printf("tiempo total: %.4f segundos\n", tiempoTotal);
    }
}
