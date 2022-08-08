package baekjoon;
// 제출할때는 패키지 빼고 클래스 이름 Main으로 수정!!!

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
public class prob_16953A에서B{
    public static void main(String args[]) {
 
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        try {
            String[] word = br.readLine().split(" ");
            long a=Integer.parseInt(word[0]);
            long b=Integer.parseInt(word[1]);
            bw.write(String.valueOf(bfs(a,b)));
            bw.flush();
            bw.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    public static long bfs(long a, long b) {
    	Queue<long[]> queue=new <long[]> LinkedList();
    	queue.offer(new long[] {a, 1});
    	while(!queue.isEmpty()) {
    		long tmp[]=queue.poll();
    		long x=tmp[0]*2;
    		long y=tmp[0]*10+1;
    		if(x==b || y==b)
    			return tmp[1]+1;
    		if(x<b)
	    			queue.offer(new long[] {x, tmp[1]+1});
    		if(y<b)
	    			queue.offer(new long[] {y,tmp[1]+1});
    	}
    	return -1;
    }
 
}