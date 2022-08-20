#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int R,C, maxi=1;
char ar[20][20];
bool alpha[26]={false, };
bool visited[20][20]={false, };

void dfs(int x, int y, int depth){
    for(int k=0;k<4;k++){
        int nx=x+"1012"[k]-'1';
        int ny=y+"2101"[k]-'1';
        if(nx<0 || ny<0 || nx>=R || ny>=C
        || visited[nx][ny] || alpha[(int)(ar[nx][ny]-65)])continue;

        visited[nx][ny]=true;
        alpha[(int)(ar[nx][ny]-65)]=true;
        maxi=max(maxi,depth+1);

        dfs(nx,ny,depth+1);

        visited[nx][ny]= false;
        alpha[(int)(ar[nx][ny]-65)]= false;
    }
}
int main(){
    FastIO;
    cin>>R>>C;
    for(int i=0;i<R;i++)for(int j=0;j<C;j++)cin>>ar[i][j];
    visited[0][0]=true;
    alpha[(int)(ar[0][0]-65)]=true;
    dfs(0,0,1);
    cout<<maxi;
    return 0;
}