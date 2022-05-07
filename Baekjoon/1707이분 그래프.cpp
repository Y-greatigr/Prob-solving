#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int V,E;
vector<int> v[20'001];
int visited[20'001]={0,};

void bfs(int x){
    queue<int> q;q.push(x);
    visited[x]=1;
    while(!q.empty()){
        int cur=q.front();q.pop();
        int groupNum;
        if(visited[cur]==1)groupNum=2;
        else if(visited[cur]==2)groupNum=1;
        for(int i=0;i<v[cur].size();i++){
            if(visited[v[cur][i]])continue;
            visited[v[cur][i]]=groupNum;
            q.push(v[cur][i]);
        }
    }
}
int main(){
    FastIO;
    int k;cin>>k;
    while(k--){
        bool flag=true;
        cin>>V>>E;
        for(int i=1;i<=V;i++){v[i].clear();visited[i]=0;}
        while(E--){
            int a,b;cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        for(int i=1;i<=V;i++){if(!visited[i])bfs(i);}
        for(int i=1;i<=V;i++)for(int j=0;j<v[i].size();j++)if(visited[i]==visited[v[i][j]]){flag= false, i=V; break;}
        if(flag) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
    return 0;
}