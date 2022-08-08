#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int* dijkstra(int s, vector<pair<int,int>> *dist, int n){
    int *shortest=new int[n];
    fill(shortest, shortest+n, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>> pq;
    pq.push({0,s});
    shortest[s]=0;
    while(!pq.empty()){
        int cur=pq.top().second, cost=pq.top().first;pq.pop();
        for(int i=0;i<dist[cur].size();i++){
            int next=dist[cur][i].first, ncost=dist[cur][i].second;
            if(shortest[next]>cost+ncost){
                shortest[next]=cost+ncost;
                pq.push({shortest[next], next});
            }
        }
    }
    return shortest;
}
int main(){
    FastIO;
    int T;cin>>T;
    while(T--){
        int n,m,t,s,g,h, dd;cin>>n>>m>>t>>s>>g>>h;
        vector<pair<int,int>> dist[n];
        vector<int> des;
        vector<int> ans;
        while(m--){
            int a,b,c;cin>>a>>b>>c;
            dist[a-1].emplace_back(b-1,c);
            dist[b-1].emplace_back(a-1,c);
            if((a==g && b==h) || (a==h && b==g))dd=c;
        }
        for(int i=0;i<t;i++){
            int a;cin>>a;
            des.push_back(a-1);
        }
        sort(des.begin(),des.end());
        int *ds=dijkstra(--s, dist, n);
        int *dg=dijkstra(--g, dist, n);
        int *dh=dijkstra(--h, dist, n);
        for(int de : des){
            if(ds[de]==ds[h]+dg[de]+dd || ds[de]==ds[g]+dd+dh[de])cout<<de+1<<" ";
        }
        cout<<'\n';
    }

    return 0;
}