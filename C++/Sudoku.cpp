#include <iostream>    // Incluye la biblioteca para la entrada y salida estándar
#include <vector>      // Incluye la biblioteca para usar el contenedor vector
#include <ctime>       // Incluye la biblioteca para medir el tiempo

// Función para imprimir el tablero de Sudoku
void imprimir_tablero(const std::vector<std::vector<int>>& tablero) {
    for (int fila = 0; fila < 9; ++fila) { // Itera sobre cada fila del tablero
        if (fila % 3 == 0 && fila != 0) {   // Imprime una línea divisoria después de cada grupo de 3 filas
            std::cout << "+---+---+---+---+---+" << std::endl;
        }

        for (int columna = 0; columna < 9; ++columna) { // Itera sobre cada columna en la fila actual
            if (columna % 3 == 0 && columna != 0) {   // Imprime una barra divisoria después de cada grupo de 3 columnas
                std::cout << "| ";
            }
            if (columna == 8) {  // Si es la última columna, maneja el formato de impresión
                std::cout << (tablero[fila][columna] == 0 ? " " : std::to_string(tablero[fila][columna])) << std::endl;
            } else {
                std::cout << (tablero[fila][columna] == 0 ? " " : std::to_string(tablero[fila][columna])) << " ";
            }
        }
    }
}

// Función para verificar si un número es válido en una posición específica
bool es_valido(const std::vector<std::vector<int>>& tablero, int numero, int fila, int columna) {
    // Verificar la fila
    for (int i = 0; i < 9; ++i) {
        if (tablero[fila][i] == numero) {
            return false; // El número ya está en la fila
        }
    }

    // Verificar la columna
    for (int i = 0; i < 9; ++i) {
        if (tablero[i][columna] == numero) {
            return false; // El número ya está en la columna
        }
    }

    // Verificar el cuadrante de 3x3
    int cuadrante_x = columna / 3;  // Calcula el índice del cuadrante en el eje x
    int cuadrante_y = fila / 3;     // Calcula el índice del cuadrante en el eje y

    for (int i = cuadrante_y * 3; i < cuadrante_y * 3 + 3; ++i) {  // Itera sobre las filas del cuadrante
        for (int j = cuadrante_x * 3; j < cuadrante_x * 3 + 3; ++j) {  // Itera sobre las columnas del cuadrante
            if (tablero[i][j] == numero) {
                return false; // El número ya está en el cuadrante de 3x3
            }
        }
    }

    return true; // El número puede ser colocado en la posición
}

// Función para encontrar un espacio vacío en el tablero
bool encontrar_vacio(const std::vector<std::vector<int>>& tablero, int& fila, int& columna) {
    for (fila = 0; fila < 9; ++fila) { // Itera sobre cada fila del tablero
        for (columna = 0; columna < 9; ++columna) { // Itera sobre cada columna en la fila actual
            if (tablero[fila][columna] == 0) {
                return true; // Devuelve true si encuentra una celda vacía
            }
        }
    }
    return false; // No se encontró ninguna celda vacía
}

// Función para resolver el tablero utilizando backtracking
bool resolver_tablero(std::vector<std::vector<int>>& tablero) {
    int fila, columna;
    if (!encontrar_vacio(tablero, fila, columna)) { // Encuentra una posición vacía en el tablero
        return true; // No hay espacios vacíos, el tablero está completo
    }

    for (int numero = 1; numero <= 9; ++numero) { // Prueba números del 1 al 9
        if (es_valido(tablero, numero, fila, columna)) { // Verifica si el número es válido en la posición
            tablero[fila][columna] = numero; // Coloca el número en la posición

            if (resolver_tablero(tablero)) { // Intenta resolver el tablero recursivamente
                return true; // El tablero se resolvió correctamente
            }

            tablero[fila][columna] = 0; // Deshace la asignación si no se pudo resolver
        }
    }

    return false; // No se pudo resolver el tablero
}

int main() {
    // Tablero de Sudoku predefinido (siempre será el mismo)
    std::vector<std::vector<int>> tablero = {
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

    std::cout << "Tablero de Sudoku inicial:\n" << std::endl;
    imprimir_tablero(tablero); // Imprime el tablero inicial

    clock_t start_time = clock(); // Marca el inicio del tiempo

    if (resolver_tablero(tablero)) { // Intenta resolver el tablero
        clock_t end_time = clock(); // Marca el fin del tiempo
        std::cout << "\nTablero de Sudoku resuelto:\n" << std::endl;
        imprimir_tablero(tablero); // Imprime el tablero resuelto
        std::cout << "\nTiempo de resolución: " << double(end_time - start_time) / CLOCKS_PER_SEC << " segundos" << std::endl;
    } else {
        std::cout << "\nNo se pudo resolver el Sudoku." << std::endl; // Mensaje si no se puede resolver
    }

    return 0; // Fin del programa
}
