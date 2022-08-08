#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int main(){
    FastIO;
    int n,m;cin>>n>>m;
    int d[n][n];
    for(int i=0;i<n;i++)fill(d[i],d[i]+n,INT_MAX);
    while(m--){
        int a,b,c;cin>>a>>b>>c;
        d[a-1][b-1]=min(c,d[a-1][b-1]);
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            if(i==k)continue;
            for(int j=0;j<n;j++){
                if(j==k || d[i][k]==INT_MAX || d[k][j]==INT_MAX)continue;
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
    for(int i=0;i<n;i++){
        if(d[0][i]!=INT_MAX && d[i][i]<0){
            cout<<-1;
            return 0;
        }
    }
    for(int i=1;i<n;i++)cout<<(d[0][i]==INT_MAX?-1:d[0][i])<<'\n';
    return 0;
}