#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int n;
int ar[16][16], visited[16][1<<16];
int dfs(int cur, int visit){
    if(visit==(1<<n)-1){
        if(!ar[cur][0])return 1'000'000'000;
        return ar[cur][0];
    }
    int &tmp=visited[cur][visit];
    if(tmp)return tmp;
    tmp=1'000'000'000;
    for(int i=1;i<n;i++){
        if(visit&(1<<i) || !ar[cur][i])continue;
        tmp=min(tmp, dfs(i,(visit|(1<<i)))+ar[cur][i]);
    }
    return tmp;
}
int main(){
    FastIO;
    cin>>n;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>ar[i][j];
    cout<<dfs(0,1);
    return 0;
}