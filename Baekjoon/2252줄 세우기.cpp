#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int ar[32'001]={0,};
vector<int> v[32'001];
int main(){
    FastIO;
    int n, m;cin>>n>>m;
    while(m--){
        int a,b;cin>>a>>b;
        v[a].push_back(b);
        ar[b]++;
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(!ar[i])q.push(i);
    }
    while(!q.empty()){
        int cur=q.front();q.pop();
        cout<<cur<<" ";
        for(int i=0;i<v[cur].size();i++){
            if(!--ar[v[cur][i]]){
                q.push(v[cur][i]);
            }
        }
    }
    return 0;
}