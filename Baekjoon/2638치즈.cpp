#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int N,M;
bool ex_ox[100][100]={false, };
int ar[100][100]={0, };
queue<pair<int,int>> q;

void check(){
    queue<pair<int,int>> qq;
    bool visited[100][100]={false,};
    qq.push({0,0});
    ex_ox[0][0]=true;
    visited[0][0]= true;
    while(!qq.empty()) {
        int x = qq.front().first, y = qq.front().second;
        qq.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + "1012"[i] - '1';
            int ny = y + "2101"[i] - '1';
            if (nx < 0 || ny < 0 || nx >= N || ny >= M
                || visited[nx][ny] || ar[nx][ny])
                continue;
            ex_ox[nx][ny] = true;
            visited[nx][ny]=true;
            qq.push({nx, ny});
        }
    }
}
void wave(queue<pair<int,int>> &q1, queue<pair<int,int>> &q2){
    while (!q1.empty()) {
        int x = q1.front().first, y = q1.front().second;
        q1.pop();
        int sum = 0;
        for (int i = 0; i < 4; i++) {
            int nx = x + "1012"[i] - '1';
            int ny = y + "2101"[i] - '1';
            if (nx < 0 || ny < 0 || nx >= N || ny >= M || ar[nx][ny] == 1 || !ex_ox[nx][ny])
                continue;
            sum++;
        }
        if (sum < 2)q2.push({x,y});
        else ar[x][y]=0;
    }
}
int main(){
    FastIO;
    int cnt=0;
    queue<pair<int,int>> second_q;
    cin>>N>>M;
    for(int i=0;i<N;i++)for(int j=0;j<M;j++){
        cin>>ar[i][j];
        if(ar[i][j])q.push({i,j});
    }
    while(!q.empty() || !second_q.empty()){
        check();
        if(second_q.empty()) wave(q, second_q);
        else wave(second_q, q);
        cnt++;
    }
    cout<<cnt;
    return 0;
}