import java.util.*;
public class Saldo {
      public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int num=12;
        double i =0;
        while(num>0){
        double n = in.nextDouble();
        i+=n;
           num--; 
        }
        System.out.println("$" + String.format("%.2f", i / 12.0));
    }
}