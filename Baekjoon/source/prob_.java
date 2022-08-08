package baekjoon;
// 제출할때는 패키지 빼고 클래스 이름 Main으로 수정!!!

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
public class prob_{
    public static void main(String args[]) {
 
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        try {
            int n = Integer.parseInt(br.readLine());

            for(int i=0; i<n; i++) {
                String[] word = br.readLine().split(" ");

                bw.write(Integer.parseInt(word[0])+Integer.parseInt(word[1])+"\n");
            }
            bw.flush();
            bw.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
 
}