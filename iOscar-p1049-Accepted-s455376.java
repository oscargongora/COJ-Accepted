import java.util.Scanner;

public class Main{
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		long sum = 0;
		if (n <= 0) {
			for (int i = n; i <= -1; i++) {
				sum += i;
			}
			System.out.print(sum + 1);
		} else {
			System.out.println((n * (n + 1)) / 2);
		}

	}
}
