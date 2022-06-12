/**
 * 문제 설명
마카롱 게임은 6 x 6 크기 게임 보드에 위에서 아래 방향으로 마카롱을 하나씩 떨어뜨려 같은 색 마카롱이 상, 하, 좌, 우 방향으로 3개 이상 연결되면 터지는 게임입니다. 마카롱은 항상 빈칸 없이 가장 아래부터 차곡차곡 쌓입니다. 또, 마카롱이 터져서 없어지면 위 칸의 마카롱이 차례대로 아래 칸으로 떨어집니다. 만약, 떨어진 마카롱이 다시 3개 이상 연결된다면 연결된 마카롱도 연쇄적으로 터지며, 더 터지는 마카롱이 없을 때까지 게임 보드 위의 마카롱이 아래 방향으로 떨어집니다. 단, 현재 게임보드에 3개 이상 연결된 마카롱이 여러 개라면 한꺼번에 터진다고 가정합니다.

아래는 게임이 진행되는 예시입니다. 처음에 게임 보드 각 칸은 전부 빈 상태입니다.

1.
1번 → 2번 → 1번 → 3번 → 6번 → 3번 위치 순서로 각 색상의 마카롱을 떨어트린 후 보드 상태는 아래 그림과 같습니다.

macaron_11.png

2.
3번 → 3번 → 3번 위치 순서로 마카롱을 떨어트리면 아래 그림과 같습니다.

macaron_12.png

3.
2번 위치에서 분홍색 마카롱을 떨어뜨리면 아래 그림과 같이 'X' 표시된 마카롱 4개가 연결되어 없어집니다.

macaron_13.png

4.
분홍색 마카롱이 없어진 후, 남은 마카롱이 모두 아래 방향으로 떨어집니다. 다시 'X' 표시된 보라색 마카롱 3개가 연결되어 없어집니다.

macaron_14.png

5.
남은 마카롱이 모두 아래로 떨어진 후 게임 보드 상태는 아래 그림과 같습니다.

maracon_15.png

어떤 위치에 무슨 색 마카롱을 떨어뜨렸는지에 대한 정보를 담은 2차원 배열 macaron이 매개변수로 주어질 때, 게임이 모두 진행된 후 게임 보드의 상태를 문자열 형태로 return 하도록 solution 함수를 완성해주세요.

제한사항
macaron의 세로(행) 길이는 1 이상 100 이하이며, 가로(열) 길이는 2입니다.
macaron의 각 행에는 마카롱을 떨어뜨린 정보가 [떨어뜨린 위치, 마카롱의 색] 형태로 담겨있습니다.
마카롱을 떨어뜨린 위치는 1 이상 6 이하인 자연수입니다.
마카롱의 색은 1 이상 9 이하인 자연수 형태로 표현하며, 같은 색상의 마카롱은 같은 숫자로 표현합니다.
마카롱이 보드 밖으로 나가도록 하거나, 마카롱이 최대 높이까지 쌓인 줄에 다시 마카롱을 떨어뜨리는 경우는 없습니다.
정답은 길이가 6인 문자열 6개를 return 해주세요.
return 하는 배열의 첫 번째 원소는 게임 보드의 가장 윗 열을 나타내며, 이후 가장 아래 열까지 순서대로 넣으면 됩니다.
게임 보드에서 빈칸은 0, 마카롱이 채워진 칸은 해당 마카롱의 색을 나타내는 자연수를 채우면 됩니다.
입출력 예
macaron	result
[[1,1],[2,1],[1,2],[3,3],[6,4],[3,1],[3,3],[3,3],[3,4],[2,1]]	["000000","000000","000000","000000","000000","204004"]
[[1,1],[1,2],[1,4],[2,1],[2,2],[2,3],[3,4],[3,1],[3,2],[3,3],[3,4],[4,4],[4,3],[5,4],[6,1]]	["000000","000000","000000","000000","000000","404001"]
입출력 예 설명
입출력 예 #1

문제의 예시와 같습니다.

입출력 예 #2

1.
5번 위치에서 4번 색상 마카롱을 떨어뜨리면 연쇄적으로 마카롱이 터지기 시작합니다.

macaron_101.png

2.
macaron_102.png

3.
현재 게임 보드에서 3개 이상 연결된 마카롱이 한꺼번에 터진 후 남은 마카롱이 아래 방향으로 떨어집니다. 따라서 1번, 2번 색상 마카롱(아래 그림에서 'X' 표시된 마카롱)이 한꺼번에 터진 후 남은 마카롱이 아래 방향으로 떨어집니다.

macaron_103.png

4.
마지막으로 3번 색상 마카롱이 터지고 6번 위치에서 1번 색상 마카롱을 떨어뜨립니다.

macaron_105.png

5.
따라서 return 하는 게임보드 상태는 다음과 같습니다.

macaron_106.png
 */

#include <string>
#include <vector>
#include <stack>
using namespace std;

int ar[6][6]={0,};
void drop(){
    for(int d=0;d<6;d++){
        int top=5;
        for(int row=5;row>=0;row--){
            if(!ar[row][d])continue;
            if(top!=row){
                ar[top][d]=ar[row][d];
                ar[row][d]=0;
            }
            top--;
        }
    }
}
void confi(int j, int col){
    int visited[6][6]={0,};
    visited[j][col]=1;
    vector<pair<int,int>> v;
    stack<pair<int,int>> st;
    v.push_back({j, col});
    st.push({j, col});
    while(!st.empty()){
        auto cur=st.top();st.pop();
        for(int k=0;k<4;k++){
            int nx=cur.first+"1012"[k]-'1';
            int ny=cur.second+"2101"[k]-'1';
            if(nx<0 || nx>=6 || ny<0 ||ny>=6 || visited[nx][ny])continue;
            if(ar[j][col]==ar[nx][ny]){
                v.push_back({nx,ny});
                st.push({nx,ny});
                visited[nx][ny]=1;
            }
        }
    }
    if(v.size()>=3){
        for(auto cur:v)ar[cur.first][cur.second]=0;
        drop();
    }
}
vector<string> solution(vector<vector<int>> macaron) {
    vector<string> answer;
    for(int i=0;i<macaron.size();i++){
        int col=macaron[i][0]-1, j;
        for(j=5;j>=0;j--){
            if(!ar[j][col]){
                ar[j][col]=macaron[i][1];
                break;
            }
        }
        confi(j, col);
        for(int q=0;q<6;q++){
            for(int w=0;w<6;w++){
                confi(q,w);
            }
        }
    }
    for(int i=0;i<6;i++){
        string s="";
        for(int j=0;j<6;j++){
            s+=(char)(ar[i][j]+'0');
        }
        answer.push_back(s);
    }
    return answer;
}