#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int N,M;
int ar[1000][1000];
bool visited[1000][1000]={0,};

void bfs(int x, int y){
    int cnt=1;
    queue<pair<int,int>> q;
    set<pair<int,int>> s;
    visited[x][y]=true;
    q.push({x,y});
    while(!q.empty()){
        auto cur=q.front();q.pop();
        for(int k=0;k<4;k++){
            int nx=cur.first+"1012"[k]-'1';
            int ny=cur.second+"2101"[k]-'1';
            if(nx<0 || ny<0 || nx>=N || ny>=M
            || visited[nx][ny])
                continue;
            if(ar[nx][ny]){
                s.insert({nx,ny});
                continue;
            }
            cnt++;
            visited[nx][ny]=true;
            q.push({nx,ny});
        }
    }
    for(auto cur:s){
        ar[cur.first][cur.second]+=cnt;
    }
}
int main(){
    FastIO;
    cin>>N>>M;
    for(int i=0;i<N;i++)for(int j=0;j<M;j++){
        char c;cin>>c;
        ar[i][j]=c-'0';
    }
    for(int i=0;i<N;i++)for(int j=0;j<M;j++) {
        if(!ar[i][j] && !visited[i][j]){
            bfs(i,j);
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++) {
            if(!ar[i][j])cout<<0;
            else cout<<ar[i][j]%10;
        }
        cout<<'\n';
    }
    return 0;
}