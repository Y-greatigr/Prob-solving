package baekjoon;
// 제출할때는 패키지 빼고 클래스 이름 Main으로 수정!!!

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
public class prob_2206{
	static int [][] array;
	static int [][][] b;
	static int [] x= {-1,0,0,1};
	static int [] y= {0,1,-1,0};
    public static void main(String args[]) {
 
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        try {
        	String[] w = br.readLine().split(" ");
        	int m=Integer.parseInt(w[0]);
        	int n=Integer.parseInt(w[1]);
        	array=new int[m][n];
        	b=new int[m][n][2];
        	for(int i=0;i<m;i++) {
        		String s = br.readLine();
        		for(int j=0;j<n;j++) {
        			array[i][j]=s.charAt(j)-'0';
              	}
        	}
    		bw.write(String.valueOf(bfs(m-1, n-1)));
            bw.flush();
            bw.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    public static int bfs(int m, int n) {
    	Queue<int[]> queue=new <int[]> LinkedList();
    	queue.offer(new int[] {0, 0, 0});
    	array[0][0]=1;
    	b[0][0][0]=1;
    	
    	while(!queue.isEmpty()) {
    		int[] temp=queue.poll();
    		
    		if(temp[0]==m && temp[1]==n)
    			return b[m][n][temp[2]];
    		for(int k=0; k<4;k++) {
            	try {
            		int rx=temp[0]+x[k];
            		int cy=temp[1]+y[k];
            		if(array[rx][cy]==1 && temp[2]==0) {
            			queue.offer(new int[] {rx,cy, 1});
            			b[rx][cy][1]=b[temp[0]][temp[1]][0]+1;
            		}
            		if (array[rx][cy]==0 && b[rx][cy][temp[2]]==0) {
            			queue.offer(new int[] {rx,cy, temp[2]});
            			b[rx][cy][temp[2]]=b[temp[0]][temp[1]][temp[2]]+1;
            		}
            	}catch(IndexOutOfBoundsException e) {
            		continue;
            	}
            }
    	}
    	return -1;
    }
 
}