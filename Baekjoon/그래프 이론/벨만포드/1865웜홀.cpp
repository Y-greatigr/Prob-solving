#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

vector<pair<int,int>> v[501];
int dist[501]={0,};
int main(){
    FastIO;
    int T;cin>>T;
    while(T--){
        int N,M,W;cin>>N>>M>>W;
        for(int i=1;i<=N;i++){
            v[i].clear();
            dist[i]=10'000'000;
        }
        for(int i=0;i<M;i++){
            int S,E,T;cin>>S>>E>>T;
            v[S].push_back({E,T});
            v[E].push_back({S,T});
        }
        for(int i=0;i<W;i++){
            int S,E,T;cin>>S>>E>>T;
            v[S].push_back({E,-T});
        }
        dist[1]=0;
        bool flag=true;
        for(int i=1;i<=N && flag;i++)for(int j=1;j<=N && flag;j++)for(int k=0;k<v[j].size() && flag;k++){
            if(dist[j]+v[j][k].second<dist[v[j][k].first]){
                dist[v[j][k].first]=dist[j]+v[j][k].second;
                if(i==N)flag=false;
            }
        }
        cout<<(flag?"NO":"YES")<<'\n';
    }
    return 0;
}