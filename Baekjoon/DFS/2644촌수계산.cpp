#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int n, a, b, m;
int visited[101]={0, };
vector<int> v[101];
int dfs(int cur, int chon){
    if(cur==b)return chon;
    int ans=-1;
    for(int i=0;i<v[cur].size();i++){
        if(visited[v[cur][i]])continue;
        visited[v[cur][i]]=1;
        ans = dfs(v[cur][i], chon+1);
        if(ans>0) return ans;
        visited[v[cur][i]]=0;
    }
    return ans;
}
int main(){
    FastIO;
    cin>>n>>a>>b>>m;
    while(m--){
        int i,j;cin>>i>>j;
        v[i].push_back(j);
        v[j].push_back(i);
    }
    cout<<dfs(a,0);
    return 0;
}