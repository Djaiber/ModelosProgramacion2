#include <iostream>
#include <string>
#include <algorithm>
#include <chrono> // Include the chrono library

std::string suma(const std::string& num1, const std::string& num2) {
    std::string resultado = "";  
    int acarreo = 0;
    int i = num1.length() - 1;
    int j = num2.length() - 1;

    while (i >= 0 || j >= 0 || acarreo) {
        int sum = acarreo;
        if (i >= 0) sum += num1[i--] - '0';
        if (j >= 0) sum += num2[j--] - '0';
        acarreo = sum / 10;
        resultado.push_back(sum % 10 + '0');
    }

    reverse(resultado.begin(), resultado.end());
    return resultado;
}

std::string resta(const std::string& num1, const std::string& num2) {
    std::string resultado = "";
    int acarreo = 0;
    int i = num1.length() - 1;
    int j = num2.length() - 1;

    while (i >= 0 || j >= 0) {
        int sub = acarreo;
        acarreo = 0;

        if (i >= 0) sub += num1[i--] - '0';
        if (j >= 0) sub -= num2[j--] - '0';

        if (sub < 0) {
            sub += 10;
            acarreo = -1;
        }

        resultado.push_back(sub + '0');
    }

    while (resultado.size() > 1 && resultado[resultado.size() - 1] == '0') {
        resultado.erase(resultado.size() - 1);  
    }

    reverse(resultado.begin(), resultado.end());
    return resultado;
}

std::string multiplica(const std::string& num1, const std::string& num2) {
    if (num1 == "0" || num2 == "0") return "0"; 

    std::string resultado(num1.size() + num2.size(), '0');

    for (int i = num1.size() - 1; i >= 0; i--) {
        int acarreo = 0;
        for (int j = num2.size() - 1; j >= 0; j--) {
            int temp = (resultado[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + acarreo;
            acarreo = temp / 10;
            resultado[i + j + 1] = temp % 10 + '0';
        }
        resultado[i] += acarreo;
    }

    size_t startpos = resultado.find_first_not_of('0');
    if (std::string::npos != startpos) {
        return resultado.substr(startpos);
    }
    return "0";
}

std::string divide(const std::string& num1, const std::string& num2) {
    if (num2 == "0") {
        return "Error: División por cero no permitida";
    }

    if (num1 == "0" || num1 < num2) {
        return "0";  
    }

    std::string resultado = "";
    std::string resto = "0";

    for (size_t k = 0; k < num1.size(); ++k) {
        resto += num1[k];
        
     
        while (resto.size() > 1 && resto[0] == '0') {
            resto.erase(resto.begin());
        }
        
        int cociente = 0;
        while (resto.size() > 1 && resto[0] == '0') {
            resto.erase(resto.begin());  
        }
        while (resto.size() >= num2.size() && (resto > num2 || resto == num2)) {
            std::string temp_resta = resta(resto, num2);
            resto = temp_resta;
            cociente++;
        }
        resultado += (cociente + '0');
    }

    while (resultado.size() > 1 && resultado[0] == '0') {
        resultado.erase(resultado.begin());
    }

    return resultado;
}

int main() {
    std::string num1, num2;
    char opcion;

    while (true) {
        std::cout << "\nSeleccione la operación que desea realizar:" << std::endl;
        std::cout << "1. Suma" << std::endl;
        std::cout << "2. Resta" << std::endl;
        std::cout << "3. Multiplicación" << std::endl;
        std::cout << "4. División" << std::endl;
        std::cout << "5. Salir" << std::endl;
        std::cout << "Ingrese el número de la operación: ";
        std::cin >> opcion;

        if (opcion == '5') {
            std::cout << "Saliendo del programa." << std::endl;
            break;
        }

        if (opcion >= '1' && opcion <= '4') {
            std::cout << "Ingrese el primer número: ";
            std::cin >> num1;
            std::cout << "Ingrese el segundo número: ";
            std::cin >> num2;

            auto start = std::chrono::high_resolution_clock::now();  // Start time measurement

            if (opcion == '1') {
                std::cout << "Resultado de la suma: " << suma(num1, num2) << std::endl;
            } else if (opcion == '2') {
                if (num1 >= num2) {
                    std::cout << "Resultado de la resta: " << resta(num1, num2) << std::endl;
                } else {
                    std::cout << "Resultado de la resta: -" << resta(num2, num1) << std::endl;
                }
            } else if (opcion == '3') {
                std::cout << "Resultado de la multiplicación: " << multiplica(num1, num2) << std::endl;
            } else if (opcion == '4') {
                std::cout << "Resultado de la división: " << divide(num1, num2) << std::endl;
            }

            auto end = std::chrono::high_resolution_clock::now();  // End time measurement
            std::chrono::duration<double> duration = end - start;
            std::cout << "Tiempo de ejecución: " << duration.count() << " segundos" << std::endl;  // Display the duration
        } else {
            std::cout << "Opción no válida. Por favor, intente de nuevo." << std::endl;
        }
    }

    return 0;
}
