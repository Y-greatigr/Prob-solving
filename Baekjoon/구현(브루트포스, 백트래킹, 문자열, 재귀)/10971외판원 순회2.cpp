#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

bool visited[10]={false,};
int ar[10][10];
int n, mini=1'000'000'000;
void dfs(int cur, int cnt, int sum){
    if(cnt==n-1){
        if(!ar[cur][0])return;
        mini=min(mini, sum+ar[cur][0]);
        return;
    }
    for(int i=1;i<n;i++){
        if(visited[i] || !ar[cur][i])continue;
        visited[i]=true;
        dfs( i, cnt+1, sum+ar[cur][i]);
        visited[i]=false;
    }
}
int main(){
    FastIO;
    cin>>n;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>ar[i][j];
    dfs(0, 0, 0);
    cout<<mini;
    return 0;
}