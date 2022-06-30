#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

char ar[50][50];
int visited[50][50][64]={0,};
int main(){
    FastIO;
    int n,m;cin>>n>>m;
    queue<tuple<int,int,int>> q;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)fill(visited[i][j],visited[i][j]+64, -1);
    for(int i=0;i<n;i++)for(int j=0;j<m;j++){
        cin>>ar[i][j];
        if(ar[i][j]=='0'){
            q.push({i,j, 0});
            visited[i][j][0]=0;
        }
    }
    while(!q.empty()){
        int x=get<0>(q.front()), y=get<1>(q.front());
        int key=get<2>(q.front());q.pop();
        for(int i=0;i<4;i++){
            int nx=x+"1012"[i]-'1';
            int ny=y+"2101"[i]-'1';
            if(nx<0 || ny<0 || nx>=n || ny>=m
                || ar[nx][ny]=='#' || visited[nx][ny][key]>-1)continue;
            if(ar[nx][ny]=='1'){
                cout<<visited[x][y][key]+1;
                return 0;
            }
            else if(ar[nx][ny]>='a' && ar[nx][ny]<='f'){
                int nkey=key|(1<<(ar[nx][ny]-'a'));
                q.push({nx,ny,nkey});
                visited[nx][ny][nkey]=visited[x][y][key]+1;
            }
            else if(ar[nx][ny]>='A' && ar[nx][ny]<='F'){
                if(key & (1<<(ar[nx][ny]-'A'))) {
                    q.push({nx,ny,key});
                    visited[nx][ny][key]=visited[x][y][key]+1;
                }
            }
            else{
                q.push({nx,ny,key});
                visited[nx][ny][key]=visited[x][y][key]+1;
            }
        }
    }
    cout<<-1;
    return 0;
}