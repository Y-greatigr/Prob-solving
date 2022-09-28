#include <bits/stdc++.h>

using namespace std;

int n,m,k, maxi=0;
bool ar[101][101]={false, }, visited[101][101]={false,};
int cnt[101][101]={0,};
void bfs(int x, int y){
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y]=true;
    cnt[x][y]++;
    while(!q.empty()){
        auto [xx,yy]=q.front();q.pop();
        for(int k=0;k<4;k++){
            int nx=xx+"1012"[k]-'1';
            int ny=yy+"2101"[k]-'1';
            if(nx<=0 || ny<=0 || nx>n || ny>m
               || !ar[nx][ny] || visited[nx][ny])continue;
            visited[nx][ny]=true;
            q.push({nx,ny});
            cnt[x][y]++;
        }
    }
    maxi=max(maxi,cnt[x][y]);
}
int main(){
    cin>>n>>m>>k;
    while(k--){
        int r,c;cin>>r>>c;
        ar[r][c]=true;
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
            if(ar[i][j] && !visited[i][j]){
                bfs(i,j);
            }
        }
    cout<<maxi;
    return 0;
}