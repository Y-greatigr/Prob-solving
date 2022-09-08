#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int ranking[10'001]={0,};
bool visited[10'001];
vector<int> v[10'001];
int main(){
    FastIO;
    int n,m, max_of_max=0;cin>>n>>m;
    while(m--){
        int a,b;cin>>a>>b;
        v[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        memset(visited,false, sizeof(visited));
        queue<int> q;q.push(i);
        visited[i]=true;
        int cnt=1;
        while(!q.empty()){
            int cur=q.front();q.pop();
            for(int j=0;j<v[cur].size();j++){
                if(visited[v[cur][j]])continue;
                visited[v[cur][j]]=true;
                q.push(v[cur][j]);
                cnt++;
            }
        }
        ranking[i]=cnt;
        max_of_max=max(cnt,max_of_max);
    }
    vector<int> ans;
    for(int i=1;i<=n;i++) if(ranking[i]==max_of_max)cout<<i<<" ";
    return 0;
}