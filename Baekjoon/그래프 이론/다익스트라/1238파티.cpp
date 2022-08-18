#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int dist[1001];
int ar[1001][2];
vector<pair<int,int>> v[1001];
void dijkstra(int n, int cur, int x){
    fill(dist, dist+n+1, 100'000'000);
    dist[cur]=0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, cur});

    while(!pq.empty()){
        int cost=pq.top().first;
        int curr=pq.top().second;
        pq.pop();

        for(int i=0;i<v[curr].size();i++){
            int next=v[curr][i].first;
            int price=v[curr][i].second;
            if(dist[next]>price+cost){
                dist[next]=price+cost;
                pq.push({dist[next], next});
            }
        }
    }

    if(cur==x){
        for(int i=1;i<=n;i++){
            if(i!=x)ar[i][1]=dist[i];
        }
    }
    else{
        ar[cur][0]=dist[x];
    }
}
int main(){
    FastIO;
    int n,m,x, maxi=0;cin>>n>>m>>x;
    for(int i=0;i<m;i++){
        int a,b,t;cin>>a>>b>>t;
        v[a].push_back({b,t});
    }
    for(int i=1;i<=n;i++)dijkstra(n, i, x);
    for(int i=1;i<=n;i++){
        if(i!=x)maxi=max(maxi,ar[i][0]+ar[i][1]);
    }
    cout<<maxi;
    return 0;
}