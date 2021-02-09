package baekjoon;
// 제출할때는 패키지 빼고 클래스 이름 Main으로 수정!!!

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
public class prob_1697{
	static int [] array;
	static boolean []b;
	static int [] x= {-1,1,0};
	static int [] y= {1,1,2};
    public static void main(String args[]) {
 
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        try {
            String[] word = br.readLine().split(" ");
            int s=Integer.parseInt(word[0]);
            int e=Integer.parseInt(word[1]);
            if (s<e) {
            	array=new int[e*2];
            	b=new boolean[e*2];
                bw.write(String.valueOf(bfs(s, e)-1));
            }
            else if(s>e){
            	array=new int[s+1];
            	b=new boolean[s+1];
                bw.write(String.valueOf(bfs(s, e)-1));
            }
            else {
            	bw.write(String.valueOf(0));
            }
            
            bw.flush();
            bw.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    public static int bfs(int start, int end) {
    	Queue<Integer> queue=new <Integer> LinkedList();
    	queue.offer(start);
    	array[start]=1;
    	b[start]=true;
    	
    	while(!queue.isEmpty()) {
    		int temp=queue.poll();
    		
    		for(int k=0; k<3;k++) {
            	try {
            		int rx=temp*y[k]+x[k];
            		if(rx==end) {
            			return array[temp]+1;
            		}
            		if (!b[rx]) {
            			queue.offer(rx);
            			b[rx]=true;
            			array[rx]=array[temp]+1;
            		}
            	}catch(IndexOutOfBoundsException e) {
            		continue;
            	}
            }
    	}
    	return 0;
    }
}