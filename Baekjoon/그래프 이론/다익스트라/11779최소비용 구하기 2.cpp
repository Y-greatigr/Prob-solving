#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int dist[1'001];
int pre[1'001];
vector<pair<int,int>> v[1'001];
vector<int> ans;
void dijkstra(int st, int en){
    fill(dist, dist+1001, 100'000'000);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, st});
    dist[st]=0;

    while(!pq.empty()){
        auto [ cost, cur]=pq.top();
        pq.pop();
        if(dist[cur]<cost)continue;
        for(auto [next, next_cost] : v[cur]){
            if(dist[next]>cost+next_cost){
                dist[next]=cost+next_cost;
                pre[next]=cur;
                pq.push({dist[next], next});
            }
        }
    }
}
int main(){
    FastIO;
    int n,m,st,en;cin>>n>>m;
    while(m--){
        int a,b,c;cin>>a>>b>>c;
        v[a].push_back({b,c});
    }
    cin>>st>>en;

    dijkstra(st, en);
    int tmp=en;
    while(st!=tmp){
        ans.push_back(tmp);
        tmp=pre[tmp];
    }
    ans.push_back(st);
    reverse(ans.begin(), ans.end());

    cout<<dist[en]<<'\n'<<ans.size()<<'\n';
    for(auto i:ans)cout<<i<<" ";

    return 0;
}