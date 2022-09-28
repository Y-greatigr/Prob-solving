#include <bits/stdc++.h>

using namespace std;

int r,c,k, maxi=0;
char ar[5][5];
bool visited[5][5]={false, };
void dfs(int x, int y, int cnt){
    if(cnt==k){
        if(x==0 && y==c-1)maxi++;
        return;
    }
    for(int k=0;k<4;k++){
        int nx=x+"1012"[k]-'1';
        int ny=y+"2101"[k]-'1';
        if(nx<0 || ny<0 || nx>=r || ny>=c
           || ar[nx][ny]=='T' || visited[nx][ny])continue;
        visited[nx][ny]=true;
        dfs(nx,ny,cnt+1);
        visited[nx][ny]=false;
    }
}
int main(){
    cin>>r>>c>>k;
    for(int i=0;i<r;i++)for(int j=0;j<c;j++)cin>>ar[i][j];
    visited[r-1][0]=true;
    dfs(r-1,0, 1);
    cout<<maxi;
    return 0;
}