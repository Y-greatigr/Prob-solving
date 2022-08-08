package baekjoon;
// 제출할때는 패키지 빼고 클래스 이름 Main으로 수정!!!

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
public class prob_1260{
	static int [][] array;
	static boolean []b;
	static boolean []c;
    public static void main(String args[]) {
 
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        try {
            String[] word = br.readLine().split(" ");
            int N=Integer.parseInt(word[0]);
            int M=Integer.parseInt(word[1]);
            int V=Integer.parseInt(word[2]);
            array=new int[N][N];
            b=new boolean[N];
            c=new boolean[N];

            for(int i=0; i<M; i++) {
                String[] aa = br.readLine().split(" ");
                array[Integer.parseInt(aa[0])-1][Integer.parseInt(aa[1])-1]=1;
                array[Integer.parseInt(aa[1])-1][Integer.parseInt(aa[0])-1]=1;
            }
            dfs(V-1, N);
            System.out.println();
            bfs(V-1, N);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    public static void dfs(int v, int n) {
    	if (b[v])
    		return;
    	b[v]=true;
		System.out.print((v+1)+" ");
    	for(int i=0;i<n;i++) {
			if(array[v][i]==1) {
				dfs(i,n);
			}
    	}
    }
    public static void bfs(int v, int n) {
    	Queue<Integer> queue=new <Integer> LinkedList();
    	queue.offer(v);
    	c[v]=true;
    	while(!queue.isEmpty()) {
    		int tmp=queue.poll();
    		System.out.print((tmp+1)+" ");
    		for(int i=0;i<n;i++) {
    			if(array[tmp][i]==1 && !c[i]) {
    				queue.offer(i);
    				c[i]=true;
    			}
        	}
    	}
    	
    }
}