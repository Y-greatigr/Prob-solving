#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>
using namespace std;

bool visited[50][50]={false, };
int solution(vector<string> grid, int k) {
    int answer = INT_MAX;
    queue<tuple<int,int,int>> q;
    q.push({0,0,0});
    visited[0][0]= true;
    int end_x=grid.size()-1, end_y=grid[0].length()-1;
    while(!q.empty()){
        int x=get<0>(q.front());
        int y=get<1>(q.front());
        int sleep=get<2>(q.front());q.pop();
        if(x==end_x && y==end_y){
            answer=min(answer,sleep);
            break;
        }
        for(int cnt=0;cnt<k;cnt++){
            queue<tuple<int,int,int>> q2;
            bool visited2[50][50]={false, };
            q2.push({x,y, 0});
            visited2[x][y]=true;
            while(!q2.empty()){
                int nx=get<0>(q2.front()), ny=get<1>(q2.front());
                int cnt2=get<2>(q2.front());q2.pop();
                if(cnt2>cnt){
                    if(visited[nx][ny] || grid[nx][ny]=='F')continue;
                    q.push({nx,ny,sleep+1});
                    visited[nx][ny]=true;
                    continue;
                }
                for(int i=0;i<4;i++){
                    int nnx=nx+"1012"[i]-'1';
                    int nny=ny+"2101"[i]-'1';
                    if(nnx<0 || nny<0 || nnx>end_x || nny>end_y
                       || grid[nnx][nny]=='#' || visited2[nnx][nny])
                        continue;
                    q2.push({nnx,nny,cnt2+1});
                    visited2[nnx][nny]=true;
                }
            }
        }
    }
    return answer-1;
}
int main(){
    cout<<solution({"..FF", "###F", "###."}, 4);
    return 0;
}