package baekjoon;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Collections;
import java.util.LinkedList;
public class prob_2606{
	public static LinkedList<Integer>[] nodeList;
	static int a;
    public static void main(String args[]) {
 
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        try {
            int n = Integer.parseInt(br.readLine());
            int k = Integer.parseInt(br.readLine());
            nodeList = new LinkedList[n+1];
            
            for(int i=0; i <= n; i++) {
                nodeList[i] = new LinkedList<Integer>();
            }
            
            for(int i=0; i < k; i++) {
            	String[] word = br.readLine().split(" ");
                
                int node1 = Integer.parseInt(word[0]);
                int node2 = Integer.parseInt(word[1]);
                
                nodeList[node1].add(node2);
                nodeList[node2].add(node1);
                
                Collections.sort(nodeList[node1]);
                Collections.sort(nodeList[node2]);
            }
            boolean[] dfsVisited = new boolean[n+1];
            dfs(1, dfsVisited);
            bw.write((a-1) + "\n");
        
            bw.flush();
            bw.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    public static void dfs(int node, boolean[] visited) {
        if(visited[node]) return;
        
        visited[node] = true;
        a++;
        for(int nextNode:nodeList[node]) {
            dfs(nextNode, visited);
        }
    }
 
}