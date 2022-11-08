#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int N, maxi_black=0, maxi_white=0;
bool ar[10][10];
bool visited_left_down[20]={false,}, visited_right_down[20]={false, };
void dfs(int cur, int cnt, int color){
    if(cur>=N*N){
        if(!color)maxi_black=max(maxi_black, cnt);
        else maxi_white=max(maxi_white, cnt);
        return;
    }

    int x=cur/N, y=cur%N;
    int jump=2;
    if(!(N%2)){
        if(y==N-1)jump=1;
        else if(y==N-2)jump=3;
    }

    // 대각선에 비숍이 없어서 비숍을 놓을 경우
    if(ar[x][y] && !visited_left_down[x+y] && !visited_right_down[y-x+N]) {
        visited_left_down[x + y] = visited_right_down[y - x + N] = true;
        dfs(cur + jump, cnt + 1, color);
        visited_left_down[x + y] = visited_right_down[y - x + N] = false;
    }

    // 그냥 비숍을 안 놓을 경우
    dfs(cur+jump, cnt, color);
}
int main(){
    FastIO;
    cin>>N;
    for(int i=0;i<N;i++)for(int j=0;j<N;j++)cin>>ar[i][j];
    dfs(0, 0, 0);
    dfs(1, 0, 1);
    cout<<maxi_white+maxi_black;
    return 0;
}