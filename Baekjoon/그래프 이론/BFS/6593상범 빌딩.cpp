#include <bits/stdc++.h>

using namespace std;

int L,R,C, st_L, st_R, st_C, en_L, en_R, en_C;
char ar[30][30][30];
int visited[30][30][30];
int main(){
    cin>>L>>R>>C;
    while(L){
        for(int i=0;i<L;i++)for(int j=0;j<R;j++)for(int k=0;k<C;k++){
                    cin>>ar[i][j][k];
                    if(ar[i][j][k]=='S')st_L=i,st_R=j,st_C=k;
                    if(ar[i][j][k]=='E')en_L=i,en_R=j,en_C=k;
                    visited[i][j][k]=0;
                }
        queue<tuple<int,int,int>> q;
        q.push({st_L,st_R,st_C});
        visited[st_L][st_R][st_C]=1;
        bool flag=false;
        while(!q.empty() && !flag){
            auto [cur_L, cur_R, cur_C]=q.front();q.pop();
            for(int k=0;k<6;k++){
                int nL=cur_L+"111120"[k]-'1';
                int nR=cur_R+"101211"[k]-'1';
                int nC=cur_C+"210111"[k]-'1';
                if(nL<0 || nR<0 || nC<0 || nL>=L || nR>=R || nC>=C
                   || visited[nL][nR][nC] || ar[nL][nR][nC]=='#')continue;
                visited[nL][nR][nC]=visited[cur_L][cur_R][cur_C]+1;
                if(nL==en_L && nR==en_R && nC==en_C){
                    flag=true;
                    break;
                }
                q.push({nL,nR,nC});
            }
        }
        if(flag)cout<<"Escaped in "<<visited[en_L][en_R][en_C]-1<<" minute(s).\n";
        else cout<<"Trapped!\n";
        cin>>L>>R>>C;
    }
    return 0;
}