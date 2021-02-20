import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Calendar;
import java.util.StringTokenizer;

public class Main{

	/**
	 * @param args
	 * @throws IOException
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader bReader = new BufferedReader(new InputStreamReader(
				System.in));
		StringTokenizer sTokenizer = new StringTokenizer(bReader.readLine(),
				" ");
		StringBuffer sBuffer = new StringBuffer();
		int hour1 = Integer.parseInt((String) sTokenizer.nextElement()), min1 = Integer
				.parseInt((String) sTokenizer.nextElement()), hour2 = Integer
				.parseInt((String) sTokenizer.nextElement()), min2 = Integer
				.parseInt((String) sTokenizer.nextElement());
		while (!(hour1 == 0 && min1 == 0 && hour2 == 0 && min2 == 0)) {
			int dif = 0;
			if ((hour2 < hour1) || (hour2 == hour1 && min2 < min1)) {
				dif = 1;
			}
			sBuffer.append(diference(hour1, min1, hour2, min2, dif));
			sBuffer.append("\n");
			sTokenizer = new StringTokenizer(bReader.readLine(), " ");
			hour1 = Integer.parseInt((String) sTokenizer.nextElement());
			min1 = Integer.parseInt((String) sTokenizer.nextElement());
			hour2 = Integer.parseInt((String) sTokenizer.nextElement());
			min2 = Integer.parseInt((String) sTokenizer.nextElement());
		}
		System.out.print(sBuffer.toString());
	}

	private static long diference(int hour1, int min1, int hour2, int min2,
			int dayDif) {
		Calendar date1 = Calendar.getInstance();
		Calendar date2 = Calendar.getInstance();
		date1.set(0, 0, 0, hour1, min1);
		date2.set(0, 0, dayDif, hour2, min2);
		return (date2.getTimeInMillis() - date1.getTimeInMillis()) / 60000;
	}
}
