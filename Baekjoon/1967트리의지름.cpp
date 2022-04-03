#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

vector<pair<int,int>> v[10001];
int visited[10001]={0};
int endd, maxi=0;

void dfs(int start, int len){
    if(visited[start])return;
    visited[start]=1;
    if(maxi<len){
        endd=start;
        maxi=len;
    }
    for(auto x : v[start]){
        dfs(x.first, len+x.second);
    }
}
int main(){
    FastIO;
    int n;cin>>n;
    while(--n){
        int a,b,c;cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    dfs(1,0);
    memset(visited, 0, sizeof(visited));
    maxi=0;
    dfs(endd,0);
    cout<<maxi;
    return 0;
}
