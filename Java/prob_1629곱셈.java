package baekjoon;
// 제출할때는 패키지 빼고 클래스 이름 Main으로 수정!!!

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
public class prob_1629곱셈{
    public static void main(String args[]) {
 
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        try {
            String[] word = br.readLine().split(" ");
            long a=Integer.parseInt(word[0]);
            long b=Integer.parseInt(word[1]);
            long c=Integer.parseInt(word[2]);
            bw.write(String.valueOf(cal(a,b,c)%c));
            bw.flush();
            bw.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    public static long cal(long a, long b, long c) {
    	if(b==0)
    		return 1;
    	else if(b==1)
    		return a;
    	long tmp=cal(a,b/2,c)%c;
    	if(b%2==0)
    		return (tmp*tmp)%c;
    	else
    		return (((tmp*tmp)%c)*a)%c;
    }
}