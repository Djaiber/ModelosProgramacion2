import java.math.BigInteger;
import java.util.Scanner;

public class Operaciones {

    public static void main(String[] args) {
    	
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Ingrese el primer número: ");
        String input1 = scanner.nextLine();
        BigInteger numero1 = new BigInteger(input1);

        System.out.print("Ingrese el segundo número: ");
        String input2 = scanner.nextLine();
        BigInteger numero2 = new BigInteger(input2);

        System.out.println("\nSeleccione la operación que desea realizar:");
        System.out.println("1. Suma");
        System.out.println("2. Resta");
        System.out.println("3. Multiplicación");
        System.out.println("4. División");
        System.out.print("Ingrese el número de la operación: ");
        
        int opcion = scanner.nextInt();
        
  
        long startTime = System.currentTimeMillis();

        
        BigInteger resultado = null;

        
        switch (opcion) {
            case 1:
                resultado = numero1.add(numero2);
                System.out.println("Resultado de la suma: " + resultado);
                break;
            case 2:
                resultado = numero1.subtract(numero2);
                System.out.println("Resultado de la resta: " + resultado);
                break;
            case 3:
                resultado = numero1.multiply(numero2);
                System.out.println("Resultado de la multiplicación: " + resultado);
                break;
            case 4:
                if (!numero2.equals(BigInteger.ZERO)) {
                    resultado = numero1.divide(numero2);
                    System.out.println("Resultado de la división: " + resultado);
                } else {
                    System.out.println("División: No se puede dividir por cero.");
                }
                break;
            default:
                System.out.println("Opción no válida.");
                break;
        }

        
        long endTime = System.currentTimeMillis();
        long executionTime = endTime - startTime;
        System.out.println("Tiempo de ejecución: " + executionTime + " ms");

       
        scanner.close();
    }
}
