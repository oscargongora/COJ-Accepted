import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class Main{

	static int p;
	
	static void decode(char[] str, char[] aux, int begin, int end){
		if(begin > end) return;
		int half = (begin + end) / 2;
		aux[half] = str[p];
		p ++;
		decode(str, aux, begin, half - 1);
		decode(str, aux, half + 1, end);
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		String str;
		int len;
		while((str = reader.readLine()) != null){
			p = 0;
			len = str.length();
			char aux[] = new char[len];
			decode(str.toCharArray(), aux, 0, len - 1);
			for(int i = 0; i<len; i++){
				if(aux[i] == 'a'){
					aux[i] = 'z';
					continue;
				}
				else if(aux[i] == 'A'){
					aux[i] = 'Z';
					continue;
				}
				aux[i] = (char) ((Character.isLetter(aux[i]))? aux[i]-1: aux[i]);
			}
			System.out.println(aux);
		}	
	}
}
