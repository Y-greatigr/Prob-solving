package baekjoon;
// 제출할때는 패키지 빼고 클래스 이름 Main으로 수정!!!

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
public class prob_1012{
	static int [][] array= {{0,}};
	static boolean [][] b= {{false,}};
	static int count = 0;
	static int [] x= {-1,0,0,1};
	static int [] y= {0,1,-1,0};
    public static void main(String args[]) {
 
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        try {
            int n = Integer.parseInt(br.readLine());

            for(int i=0; i<n; i++) {
                String[] word = br.readLine().split(" ");
                array=new int[Integer.parseInt(word[0])][Integer.parseInt(word[1])];
        		b=new boolean[Integer.parseInt(word[0])][Integer.parseInt(word[1])];

                for(int p=0; p<Integer.parseInt(word[2]); p++){
                	String[] xy = br.readLine().split(" ");
                	array[Integer.parseInt(xy[0])][Integer.parseInt(xy[1])]=1;
                }
                for(int f=0; f<Integer.parseInt(word[0]); f++) {
                	for(int j=0; j<Integer.parseInt(word[1]); j++) {
                		if(array[f][j]==1 && !b[f][j]) {
                			count++;
                			dfs(f, j);
                		}
                	}
                }
                bw.write(count+"\n");
                count=0;
            }
            
            bw.flush();
            bw.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    public static void dfs(int row, int col) {
    	b[row][col]=true;
    	
        for(int i=0; i<4;i++) {
        	try {
        		int rx=row+x[i];
        		int cy=col+y[i];
        		if (array[rx][cy]==1 && !b[rx][cy]) {
        			dfs(rx,cy);        			
        		}
        	}catch(IndexOutOfBoundsException e) {
        		continue;
        	}
        }
    }
 
}