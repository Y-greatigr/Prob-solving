#include <bits/stdc++.h>
#define FastIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;

int w,h;
bool ar[50][50], visited[50][50];
void bfs(int r, int c){
    queue<pair<int,int>> q;
    q.push({r,c});
    visited[r][c]=true;
    while(!q.empty()){
        auto cur=q.front();q.pop();
        for(int k=0;k<8;k++){
            int nx=cur.first+"10001222"[k]-'1';
            int ny=cur.second+"22100012"[k]-'1';
            if(nx<0 || nx>=h || ny<0 || ny>=w
            || visited[nx][ny] || !ar[nx][ny])
                continue;
            visited[nx][ny]=true;
            q.push({nx,ny});
        }
    }
}
int main(){
    FastIO;
    cin>>w>>h;
    while(w && h){
        int ans=0;
        for(int i=0;i<h;i++)for(int j=0;j<w;j++){
            cin>>ar[i][j];
            visited[i][j]=false;
        }
        for(int i=0;i<h;i++)for(int j=0;j<w;j++){
            if(ar[i][j] && !visited[i][j]){
                ans++;
                bfs(i,j);
            }
        }
        cout<<ans<<'\n';
        cin>>w>>h;
    }
    return 0;
}