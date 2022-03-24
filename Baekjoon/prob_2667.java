package baekjoon;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
public class prob_2667{
	static int [][] array;
	static boolean [][] b;
	static int count = 0;
	static int [] x= {-1,0,0,1};
	static int [] y= {0,1,-1,0};
	static int [] num= {0,};
    public static void main(String args[]) {
 
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        try {
            int N = Integer.parseInt(br.readLine());
    		array=new int[N+1][N+1];
    		b=new boolean[N+1][N+1];
    		num=new int[N*N];

            for(int i=1; i<N+1; i++) {
            	String word = br.readLine();
            	for(int j=1; j<N+1; j++) {
            		array[i][j]=word.charAt(j-1)-'0';
            		b[i][j]=false;
            	}
            }
            for(int i=1; i<N+1; i++) {
            	for(int j=1; j<N+1; j++) {
            		if(array[i][j]==1 && !b[i][j]) {
            			count++;
            			dfs(i, j);
            		}
            	}
            }
            Arrays.sort(num);
            bw.write((count)+"\n");
            for(int k:num) {
            	if (k==0)
            		continue;
            	bw.write(k+"\n");
            }
            bw.flush();
            bw.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    public static void dfs(int row, int col) {
    	b[row][col]=true;
    	num[count-1]++;
    	
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