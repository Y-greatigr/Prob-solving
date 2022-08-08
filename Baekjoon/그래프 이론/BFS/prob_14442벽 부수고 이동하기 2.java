package baekjoon;
// 제출할때는 패키지 빼고 클래스 이름 Main으로 수정!!!

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
public class prob_14442{
	static int [][] array;
	static int [][][] b;
	static int [] x= {-1,0,0,1};
	static int [] y= {0,1,-1,0};
	static int m;
	static int n;
	static int k;
    public static void main(String args[]) {
 
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        try {
        	String[] w = br.readLine().split(" ");
        	m=Integer.parseInt(w[0]);
        	n=Integer.parseInt(w[1]);
        	k=Integer.parseInt(w[2]);
        	array=new int[m][n];
        	b=new int[m][n][k+1];
        	for(int i=0;i<m;i++) {
        		String s = br.readLine();
        		for(int j=0;j<n;j++) {
        			array[i][j]=s.charAt(j)-'0';
              	}
        	}
    		bw.write(String.valueOf(bfs()));
            bw.flush();
            bw.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    public static int bfs() {
    	Queue<int[]> queue=new <int[]> LinkedList();
    	queue.offer(new int[] {0, 0, 0});
    	array[0][0]=1;
    	b[0][0][0]=1;
    	
    	while(!queue.isEmpty()) {
    		int[] temp=queue.poll();
    		
    		if(temp[0]==m-1 && temp[1]==n-1)
    			return b[temp[0]][temp[1]][temp[2]];
    		for(int t=0; t<4;t++) {
        		int rx=temp[0]+x[t];
        		int cy=temp[1]+y[t];
        		int pk=temp[2]+1;
        		if (rx<0 || rx>=m || cy<0 || cy>=n)
        			continue;
        		if (b[rx][cy][temp[2]]!=0)
        			continue;
        		if(array[rx][cy]==1 && temp[2]<k) {
        			queue.offer(new int[] {rx,cy, pk});
        			b[rx][cy][pk]=b[temp[0]][temp[1]][temp[2]]+1;
        		}
        		else if (array[rx][cy]==0) {
        			queue.offer(new int[] {rx,cy, temp[2]});
        			b[rx][cy][temp[2]]=b[temp[0]][temp[1]][temp[2]]+1;
        		}
            }
    	}
    	return -1;
    }
 
}