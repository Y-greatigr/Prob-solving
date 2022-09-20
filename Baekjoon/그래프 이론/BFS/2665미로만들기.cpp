#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int ar[50][50];
int changed[50][50];
int main(){
    FastIO;
    int n;cin>>n;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++){
        char c;cin>>c;
        ar[i][j]=c-'0';
        changed[i][j]=100'000'000;
    }
    queue<pair<int,int>> q;
    q.push({0,0});
    changed[0][0]=0;
    while(!q.empty()){
        auto [x,y]=q.front();q.pop();
        for(int k=0;k<4;k++){
            int nx=x+"1012"[k]-'1';
            int ny=y+"2101"[k]-'1';
            if(nx<0 || ny<0 || nx>=n || ny>=n)continue;
            if(ar[nx][ny] && changed[nx][ny]>changed[x][y]){
                q.push({nx,ny});
                changed[nx][ny]=changed[x][y];
            }
            else if(!ar[nx][ny] && changed[nx][ny]>changed[x][y]+1){
                q.push({nx,ny});
                changed[nx][ny]=changed[x][y]+1;
            }
        }
    }
    cout<<changed[n-1][n-1];
    return 0;
}