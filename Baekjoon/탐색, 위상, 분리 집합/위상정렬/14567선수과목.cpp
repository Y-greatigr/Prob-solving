#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int main(){
    FastIO;
    int n,m;cin>>n>>m;
    vector<int> v[n+1];
    queue<int> q;
    int ar[1001]={0,}, ans[1001]={0,};
    while(m--){
        int a,b;cin>>a>>b;
        v[a].push_back(b);
        ar[b]++;
    }
    for(int i=1;i<=n;i++){
        if(!ar[i]) {
            q.push(i);
            ans[i]=1;
        }
    }
    while(!q.empty()){
        int cur=q.front();q.pop();
        for(int i=0; i<v[cur].size();i++){
            if(!--ar[v[cur][i]]){
                q.push(v[cur][i]);
                ans[v[cur][i]]=ans[cur]+1;
            }
        }
    }
    for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
    return 0;
}