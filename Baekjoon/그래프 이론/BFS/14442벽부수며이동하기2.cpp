#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int a[1001][1001];
bool visited[1001][1001][11];
int main(){
    FastIO;
    int n, m, k; cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        string str; cin>>str;
        for(int j=0;j<m;j++){
            a[i+1][j+1]=str[j]-'0';
        }
    }
    queue<pair<pair<int,int>, pair<int,int>>> q;
    q.push({{1,1}, {0,1}});
    visited[1][1][0]=true;
    while(!q.empty()){
        auto cur=q.front(); q.pop();
        int x=cur.first.first;
        int y=cur.first.second;
        int d=cur.second.first;
        int e=cur.second.second;
        if(x==n && y==m){
            cout<<e;
            return 0;
        }
        for(int p=0;p<4;++p){
            int nx=x+"1012"[p]-'1';
            int ny=y+"2101"[p]-'1';
            if(nx<1 || ny<1 ||nx>n || ny>m)continue;
            if(a[nx][ny] && !visited[nx][ny][d+1] && d<k){
                q.push({{nx,ny},{d+1, e+1}});
                visited[nx][ny][d+1]=true;
            }
            if(!a[nx][ny] && !visited[nx][ny][d]){
                q.push({{nx,ny},{d,e+1}});
                visited[nx][ny][d]=true;
            }
        }

    }
    cout<<-1;
    return 0;
}
