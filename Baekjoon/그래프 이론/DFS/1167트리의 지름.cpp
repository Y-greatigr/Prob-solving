#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int maxi=0, end_point=0;
vector<pair<int,int>> v[100'001];
bool visited[100'001]={false, };
void dfs(int cur, int length){
    if(length>maxi){
        maxi=length;
        end_point=cur;
    }
    for(int i=0;i<v[cur].size();i++){
        if(visited[v[cur][i].first])continue;
        visited[v[cur][i].first]=true;
        dfs(v[cur][i].first, length+v[cur][i].second);
    }
}
int main(){
    FastIO;
    int V;cin>>V;
    for(int i=1;i<=V;i++){
        int n, a;cin>>n>>a;
        while(a!=-1){
            int b;cin>>b;
            v[n].push_back({a,b});
            cin>>a;
        }
    }

    // end_point를 찾기 위한 dfs
    visited[1]=true;
    dfs(1, 0);

    // end_point에서 다른 포인트를 찾기 위한 dfs
    memset(visited, false, sizeof(visited));
    maxi=0, visited[end_point]=true;
    dfs(end_point, 0);

    cout<<maxi;
    return 0;
}