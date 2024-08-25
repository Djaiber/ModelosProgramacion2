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

start_time = time.time()
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

          if opcion == '1':
              print("Resultado de la suma:", suma(num1, num2))
          elif opcion == '2':
              print("Resultado de la resta:", resta(num1, num2))
          elif opcion == '3':
              print("Resultado de la multiplicación:", multiplicacion(num1, num2))
          elif opcion == '4':
              print("Resultado de la división:", division(num1, num2))
      else:
          print("Opción no válida. Por favor, intente de nuevo.")


end_time = time.time() 
execution_time = end_time - start_time
print(f"El tiempo total de ejecución fue: {execution_time:.2f} segundos")
