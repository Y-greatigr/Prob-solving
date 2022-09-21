#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int ar[100][100];
int visited[100][100];
int main(){
    FastIO;
    int n,m;cin>>m>>n;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++){
        char c;cin>>c;
        ar[i][j]=c-'0';
        visited[i][j]=100'000'000;
    }
    queue<pair<int,int>> q;
    q.push({0,0});
    visited[0][0]=0;
    while(!q.empty()){
        auto [x,y]=q.front();q.pop();
        for(int k=0;k<4;k++){
            int nx=x+"1012"[k]-'1';
            int ny=y+"2101"[k]-'1';
            if(nx<0 || ny<0 || nx>=n || ny>=m)continue;
            if(ar[nx][ny] && visited[nx][ny]>visited[x][y]+1){
                q.push({nx,ny});
                visited[nx][ny]=visited[x][y]+1;
            }
            else if(!ar[nx][ny] && visited[nx][ny]>visited[x][y]){
                q.push({nx,ny});
                visited[nx][ny]=visited[x][y];
            }
        }
    }
    cout<<visited[n-1][m-1];
    return 0;
}