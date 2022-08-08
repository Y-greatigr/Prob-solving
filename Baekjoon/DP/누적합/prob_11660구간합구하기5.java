package baekjoon;
// 제출할때는 패키지 빼고 클래스 이름 Main으로 수정!!!

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
public class prob_11660구간합구하기5{
	static int a[][];
    public static void main(String args[]) {
    	 
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        try {
        	String[] word = br.readLine().split(" ");
        	int n = Integer.parseInt(word[0]);
        	int m = Integer.parseInt(word[1]);
        	a=new int[n+1][n+1];

            for(int i=1; i<=n; i++) {
                String[] word1 = br.readLine().split(" ");
                for(int j=1;j<=n;j++) {
                	a[i][j]=Integer.parseInt(word1[j-1]);
                	a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
                }
            }
            while(m-->0) {
            	String[] word2 = br.readLine().split(" ");
            	int b=Integer.parseInt(word2[0]);
            	int c=Integer.parseInt(word2[1]);
            	int d=Integer.parseInt(word2[2]);
            	int e=Integer.parseInt(word2[3]);
            	int sum=0;
            	sum+=(a[d][e]-a[d][c-1]-a[b-1][e]+a[b-1][c-1]);
            	bw.write(String.valueOf(sum)+'\n');
            }
            bw.flush();
            bw.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
 
}