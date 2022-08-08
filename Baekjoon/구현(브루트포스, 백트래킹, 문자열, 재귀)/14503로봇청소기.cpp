#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int a[50][50]={0,};
int main(){
    FastIO;
    int cnt=0, limit=0;
    int N,M, R, C, D;cin>>N>>M>>R>>C>>D;
    for(int i=0;i<N;i++)for(int j=0;j<M;j++)cin>>a[i][j];
    while(1){
        if(limit==4){
            int k=(D+2)%4;
            int x=R+"0121"[k]-'1';
            int y=C+"1210"[k]-'1';
            if(a[x][y]==1)break;
            R=x,C=y;
            limit=0;
        }
        if(!a[R][C])a[R][C]=2,cnt++;
        int k=(D+3)%4;
        int x=R+"0121"[k]-'1';
        int y=C+"1210"[k]-'1';
        if(!a[x][y]) R=x,C=y,D=k,limit=0;
        else D=k,limit++;
    }
    cout<<cnt;
    return 0;
}
