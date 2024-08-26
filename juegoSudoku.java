public class juegoSudoku {

    // Método para imprimir el tablero de Sudoku
    public static void imprimirTablero(int[][] tablero) {
        for (int fila = 0; fila < 9; fila++) { // Iterar sobre cada fila del tablero
            if (fila % 3 == 0 && fila != 0) { // Imprimir una línea divisoria después de cada 3 filas (excepto la primera)
                System.out.println("-----------");
            }
            for (int columna = 0; columna < 9; columna++) { // Iterar sobre cada columna de la fila actual
                if (columna % 3 == 0 && columna != 0) { // Imprimir una barra divisoria después de cada 3 columnas (excepto la primera)
                    System.out.print("|");
                }
                if (columna == 8) { // Al final de la fila, mover a la siguiente línea
                    System.out.println(tablero[fila][columna]); // Imprimir el último número de la fila y mover a la siguiente línea
                } else {
                    System.out.print(tablero[fila][columna] + " "); // Imprimir el número seguido de un espacio
                }
            }
        }
    }

    // Método para verificar si un número es válido en una posición específica
    public static boolean esValido(int[][] tablero, int numero, int fila, int columna) {
        // Verificar la fila
        for (int i = 0; i < 9; i++) { // Iterar sobre cada columna de la fila para verificar si el número ya existe
            if (tablero[fila][i] == numero) { // Si el número ya está en la fila, retorna falso
                return false;
            }
        }

        // Verificar la columna
        for (int i = 0; i < 9; i++) { // Iterar sobre cada fila de la columna para verificar si el número ya existe
            if (tablero[i][columna] == numero) { // Si el número ya está en la columna, retorna falso
                return false;
            }
        }

        // Verificar la subcuadrícula 3x3
        int cuadranteFila = fila / 3 * 3; // Calcular el inicio de la subcuadrícula en la fila
        int cuadranteColumna = columna / 3 * 3; // Calcular el inicio de la subcuadrícula en la columna
        for (int i = cuadranteFila; i < cuadranteFila + 3; i++) { // Iterar sobre las filas de la subcuadrícula
            for (int j = cuadranteColumna; j < cuadranteColumna + 3; j++) { // Iterar sobre las columnas de la subcuadrícula
                if (tablero[i][j] == numero) { // Si el número ya está en la subcuadrícula, retorna falso
                    return false;
                }
            }
        }

        return true; // Si no se encontraron conflictos, retorna verdadero
    }

    // Método para resolver el tablero de Sudoku utilizando backtracking
    public static boolean resolverTablero(int[][] tablero) {
        for (int fila = 0; fila < 9; fila++) { // Iterar sobre cada fila del tablero
            for (int columna = 0; columna < 9; columna++) { // Iterar sobre cada columna de la fila actual
                if (tablero[fila][columna] == 0) { // Si encuentra una celda vacía (valor 0)
                    for (int numero = 1; numero <= 9; numero++) { // Probar números del 1 al 9
                        if (esValido(tablero, numero, fila, columna)) { // Verificar si el número es válido en la posición
                            tablero[fila][columna] = numero; // Colocar el número en la celda

                            if (resolverTablero(tablero)) { // Intentar resolver el resto del tablero recursivamente
                                return true; // Si se resolvió correctamente, retornar verdadero
                            }

                            tablero[fila][columna] = 0; // Si no se pudo resolver, deshacer el cambio (backtracking)
                        }
                    }
                    return false; // Si ningún número es válido, retornar falso
                }
            }
        }
        return true; // Si no quedan celdas vacías, el tablero está resuelto
    }

    public static void main(String[] args) {
        // Tablero de Sudoku predefinido
        int[][] tablero = {
            {5, 3, 0, 0, 7, 0, 0, 0, 0},
            {6, 0, 0, 1, 9, 5, 0, 0, 0},
            {0, 9, 8, 0, 0, 0, 0, 6, 0},
            {8, 0, 0, 0, 6, 0, 0, 0, 3},
            {4, 0, 0, 8, 0, 3, 0, 0, 1},
            {7, 0, 0, 0, 2, 0, 0, 0, 6},
            {0, 6, 0, 0, 0, 0, 2, 8, 0},
            {0, 0, 0, 4, 1, 9, 0, 0, 5},
            {0, 0, 0, 0, 8, 0, 0, 7, 9}
        };

        // Imprimir el tablero de Sudoku sin resolver
        System.out.println("Tablero de Sudoku inicial:\n");
        imprimirTablero(tablero);

        // Marcar el inicio del tiempo
        long startTime = System.nanoTime();

        // Resolver el tablero
        if (resolverTablero(tablero)) { // Intentar resolver el tablero
            // Marcar el fin del tiempo
            long endTime = System.nanoTime();

            // Imprimir el tablero resuelto
            System.out.println("\nTablero de Sudoku resuelto:\n");
            imprimirTablero(tablero);

            // Imprimir el tiempo de resolución
            System.out.println("\nTiempo de resolución: " + (endTime - startTime) / 1e9 + " segundos");
        } else {
            System.out.println("\nNo se pudo resolver el Sudoku."); // Si no se puede resolver, imprimir mensaje de error
        }
    }
}
