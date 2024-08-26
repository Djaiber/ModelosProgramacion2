import time

def suma(a, b):
    return a + b

def resta(a, b):
    return a - b

def multiplicacion(a, b):
    return a * b

def division(a, b):
    if b != 0:
        return a / b
    else:
        return "No se puede dividir por cero"

while True:
    print("\nSeleccione la operación que desea realizar:")
    print("1. Suma")
    print("2. Resta")
    print("3. Multiplicación")
    print("4. División")
    print("5. Salir")

    opcion = input("Ingrese el número de la operación: ")

    if opcion == '5':
        print("Saliendo del programa.")
        break

    if opcion in ['1', '2', '3', '4']:
        num1 = int(input("Ingrese el primer número: "))
        num2 = int(input("Ingrese el segundo número: "))

        start_time = time.time()  # Start timing the operation

        if opcion == '1':
            resultado = suma(num1, num2)
            print("Resultado de la suma:", resultado)
        elif opcion == '2':
            resultado = resta(num1, num2)
            print("Resultado de la resta:", resultado)
        elif opcion == '3':
            resultado = multiplicacion(num1, num2)
            print("Resultado de la multiplicación:", resultado)
        elif opcion == '4':
            resultado = division(num1, num2)
            print("Resultado de la división:", resultado)

        end_time = time.time()  # End timing the operation
        execution_time = end_time - start_time
        print(f"Tiempo de ejecución de la operación: {execution_time:.6f} segundos")
    else:
        print("Opción no válida. Por favor, intente de nuevo.")
