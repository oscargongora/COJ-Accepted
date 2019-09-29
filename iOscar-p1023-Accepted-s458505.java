import java.util.Scanner;

public class Main{
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		double total = 0;
		String inString;
		for (int i = 0; i < 12; i++) {
			inString = in.next();
			total += Double.parseDouble(inString);
		}
		String outString = "$" + (Math.rint((total / 12) * 100) / 100);
		System.out.println(outString);
	}
}
