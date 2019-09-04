import java.util.Scanner;

public class Main{
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int t, n, m, pos;
		double votes[] = null, cant;
		Double temp;
		String inputString, winers = "";
		t = input.nextInt();
		while (t > 0) {
			n = input.nextInt();
			votes = new double[n];
			m = input.nextInt();
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < votes.length; j++) {
					inputString = input.next();
					votes[j] += Double.parseDouble(inputString);
				}
			}
			cant = 0;
			for (int i = 0; i < votes.length; i++) {
				cant += votes[i];
			}
			if (cant == 0) {
				winers += "0" + "\n";

			} else {
				temp = votes[0];
				pos = 1;
				for (int i = 1; i < votes.length; i++) {
					if (votes[i] > temp) {
						pos = i + 1;
						temp = votes[i];
					}
				}
				winers += (pos) + "\n";
			}
			votes = null;
			t--;
		}
		System.out.print(winers);
	}
}
