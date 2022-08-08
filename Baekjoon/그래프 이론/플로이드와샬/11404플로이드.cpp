#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int d[100][100];
int main(){
    FastIO;
    int n,m;cin>>n>>m;
    for(int i=0;i<n;i++)fill(d[i], d[i]+n, INT_MAX);
    while(m--){
        int a,b,c;cin>>a>>b>>c;
        if(d[a-1][b-1]<c)continue;
        d[a-1][b-1]=c;
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            if(i==k)continue;
            for(int j=0;j<n;j++){
                if(i==j || j==k || d[i][k]==INT_MAX || d[k][j]==INT_MAX)continue;
                if(d[i][k]+d[k][j]<d[i][j])d[i][j]=d[i][k]+d[k][j];
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)cout<<((d[i][j]==INT_MAX)?0:d[i][j])<<" ";
        cout<<'\n';
    }
    return 0;
}