package baekjoon;
// 제출할때는 패키지 빼고 클래스 이름 Main으로 수정!!!

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
public class prob_7576{
	static int [][] array;
	static boolean [][]b;
	static Queue<int[]> queue=new <int[]> LinkedList();
	static int [] x= {-1,0,0,1};
	static int [] y= {0,1,-1,0};
    public static void main(String args[]) {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        try {
        	String[] word = br.readLine().split(" ");
            int n = Integer.parseInt(word[0]);
            int m = Integer.parseInt(word[1]);
            array=new int[m][n];
            b=new boolean[m][n];

            for(int i=0; i<m; i++) {
            	String[] a = br.readLine().split(" ");
                for(int j=0;j<n;j++) {
                	array[i][j]=Integer.parseInt(a[j]);
                	if(array[i][j]==1) {
                		queue.offer(new int[] {i, j});
                		b[i][j]=true;
                	}
                }
            }
            bfs();
            int tmp=1;
            for(int i=0; i<m; i++) {
                for(int j=0;j<n;j++) {
                	if (array[i][j]==0) {
                		tmp=0;
                		i=m-1;
                		break;
                	}
                	if(array[i][j]>tmp)
                		tmp=array[i][j];
                }
            }
            if(tmp==1)
            	bw.write(String.valueOf(0));
            else
            	bw.write(String.valueOf(tmp-1));
            bw.flush();
            bw.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    public static void bfs() {
    	while(!queue.isEmpty()) {
    		int[] temp=queue.poll();
    		
    		for(int k=0; k<4;k++) {
            	try {
            		int rx=temp[0]+x[k];
            		int cy=temp[1]+y[k];
            		if (array[rx][cy]==0 && !b[rx][cy]) {
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