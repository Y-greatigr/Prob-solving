#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int N;
int dist[801];
vector<pair<int,int>> v[801];

void dijkstra(int start){
    fill(dist,dist+N+1, INT_MAX/2);
    dist[start]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, start});    // 거리, 위치
    while(!pq.empty()){
        auto cur=pq.top();pq.pop();
        for(auto x:v[cur.second]){
            if(dist[x.first]>cur.first+x.second){   // dist[목표지점] > 현재 도착 위치까지 거리 + 현재 위치부터 목표지점까지 거리
                dist[x.first]=cur.first+x.second;
                pq.push({dist[x.first], x.first});
            }
        }
    }
}
int main(){
    FastIO;
    int E,v1,v2;cin>>N>>E;
    int mini=INT_MAX;
    while(E--){
        int a,b,c;cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    cin>>v1>>v2;
    
    dijkstra(1);
    int sv1=dist[v1];
    int sv2=dist[v2];

    dijkstra(v1);
    int v1v2=dist[v2];
    int v1N=dist[N];

    dijkstra(v2);
    int v2N=dist[N];

    mini=min(mini,sv1+v1v2+v2N);
    mini=min(mini, sv2+v1v2+v1N);
    if(mini<0 || mini>=INT_MAX) cout<<-1;
    else cout<<mini;
    
    return 0;
}
