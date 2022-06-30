#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int ar[1001]={0,};
vector<int> v[1001];
int main(){
    FastIO;
    int n,m;cin>>n>>m;
    while(m--){
        int k, a;cin>>k>>a;
        for(int i=1;i<k;i++){
            int b;cin>>b;
            ar[b]++;
            v[a].push_back(b);
            a=b;
        }
    }
    queue<int> q;
    vector<int> ans;
    for(int i=1;i<=n;i++){
        if(!ar[i]){
            ans.emplace_back(i);
            q.push(i);
        }
    }
    while(!q.empty()){
        int cur=q.front();q.pop();
        for(int i=0;i<v[cur].size();i++){
            if(!--ar[v[cur][i]]){
                ans.emplace_back(v[cur][i]);
                q.push(v[cur][i]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(ar[i]){
            cout<<0;
            return 0;
        }
    }
    for(auto i:ans)cout<<i<<" ";
    return 0;
}