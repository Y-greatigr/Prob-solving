#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int n,m;
int ar[101][101], nex[101][101];
int main(){
    FastIO;
    cin>>n>>m;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)ar[i][j]=100'000'000;
    while(m--){
        int a,b,c;cin>>a>>b>>c;
        if(ar[a][b]>c){
            ar[a][b]=c;
            nex[a][b]=b;
        }
    }
    for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
        if(ar[i][j]>ar[i][k]+ar[k][j]){
            ar[i][j]=ar[i][k]+ar[k][j];
            nex[i][j]=nex[i][k];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j || ar[i][j]==100'000'000)cout<<0<<" ";
            else cout<<ar[i][j]<<" ";
        }
        cout<<'\n';
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j || ar[i][j]==100'000'000)cout<<0<<'\n';
            else{
                vector<int> v;
                int cur=i;
                while(cur!=j){
                    v.push_back(cur);
                    cur=nex[cur][j];
                }
                v.push_back(j);
                cout<<v.size()<<" ";
                for(auto k:v)cout<<k<<" ";
                cout<<'\n';
            }
        }
    }
    return 0;
}