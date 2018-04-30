package lunmijo.java;

/**
 *
 * @author Lunmijo
 */
public class CalculatorOperations {
   public static double result_of_ariphmetic_operations(int calculation, double num, double value) {
       switch (calculation) {
            case 1:
                System.out.println("num: " + num + " value: " + value);
                return (num + value);
            case 2:
                return (num - value);
            case 3:
                return (num * value);
            case 4:
                return (num / value);
   } 
       return 0;
   }
}
