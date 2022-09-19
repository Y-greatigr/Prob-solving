#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int dist[51][51];
int ans[51];
int main(){
    FastIO;
    int n, a, b, mini=100'000'000;cin>>n>>a>>b;
    for(int i=1;i<=n;i++){
        fill(dist[i]+1, dist[i]+n+1, 100'000'000);
        dist[i][i]=0;
    }
    while(a!=-1){
        dist[a][b]=1, dist[b][a]=1;
        cin>>a>>b;
    }
    for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
        if(dist[i][k]+dist[k][j]<dist[i][j])dist[i][j]=dist[i][k]+dist[k][j];
    }
    for(int i=1;i<=n;i++){
        int maxi=0;
        for(int j=1;j<=n;j++) maxi=max(maxi,dist[i][j]);
        mini=min(maxi,mini);
        ans[i]=maxi;
    }
    vector<int> ans2;
    for(int i=1;i<=n;i++) if(ans[i]==mini)ans2.push_back(i);
    cout<<mini<<" "<<ans2.size()<<'\n';
    for(auto i:ans2)cout<<i<<" ";
    return 0;
}