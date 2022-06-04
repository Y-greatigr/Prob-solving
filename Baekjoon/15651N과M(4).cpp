#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int ar[8];
void dfs(int cur, int n, int m){
    if(cur==m){
        for(int i=1;i<=m;i++)cout<<ar[i]<<" ";
        cout<<'\n';
        return;
    }
    for(int i=1;i<=n;i++){
        ar[cur+1]=i;
        dfs(cur+1, n, m);
    }
}
int main(){
    FastIO;
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        ar[1]=i;
        dfs(1, n, m);
    }
    return 0;
}