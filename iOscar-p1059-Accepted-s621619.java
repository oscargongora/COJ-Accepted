import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main{

	public static void main(String[] args) throws NumberFormatException,
			IOException {
		BufferedReader buffr = new BufferedReader(new InputStreamReader(
				System.in));
		StringBuffer sbuff = new StringBuffer();
		int n = 0;
		while ((n = Integer.parseInt(buffr.readLine())) != 0) {
			sbuff.append("The parity of ");
			sbuff.append(Integer.toBinaryString(n));
			sbuff.append(" is ");
			sbuff.append(Integer.bitCount(n));
				sbuff.append(" (mod 2).");
			sbuff.append("\n");
		}
		System.out.print(sbuff.toString());

	}

}
