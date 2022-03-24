package baekjoon;
// 제출할때는 패키지 빼고 클래스 이름 Main으로 수정!!!

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
public class prob_2178{
	static int [][] array;
	static boolean [][] b;
	static int [] x= {-1,0,0,1};
	static int [] y= {0,1,-1,0};
    public static void main(String args[]) {
 
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        try {
        	String[] w = br.readLine().split(" ");
        	array=new int[Integer.parseInt(w[0])][Integer.parseInt(w[1])];
        	b=new boolean[Integer.parseInt(w[0])][Integer.parseInt(w[1])];
        	for(int i=0;i<Integer.parseInt(w[0]);i++) {
        		String s = br.readLine();
        		for(int j=0;j<Integer.parseInt(w[1]);j++) {
        			array[i][j]=s.charAt(j)-'0';
              	}
        	}
    		bfs();
    		bw.write(array[Integer.parseInt(w[0])-1][Integer.parseInt(w[1])-1]+"\n");
            bw.flush();
            bw.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    public static void bfs() {
    	Queue<int[]> queue=new <int[]> LinkedList();
    	queue.offer(new int[] {0, 0});
    	b[0][0]=true;
    	
    	while(!queue.isEmpty()) {
    		int[] temp=queue.poll();
    		
    		for(int k=0; k<4;k++) {
            	try {
            		int rx=temp[0]+x[k];
            		int cy=temp[1]+y[k];
            		if (array[rx][cy]==1 && !b[rx][cy]) {
            			queue.offer(new int[] {rx,cy});
            			b[rx][cy]=true;
            			array[rx][cy]=array[temp[0]][temp[1]]+1;
            		}
            	}catch(IndexOutOfBoundsException e) {
            		continue;
            	}
            }
    	}
    }
 
}