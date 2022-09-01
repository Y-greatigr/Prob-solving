#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int ar[500]={0,};
int dp[500]={0,};
int times[500]={0,};
vector<int> v[500];
int main(){
    FastIO;
    int n;cin>>n;
    for(int i=0;i<n;i++){
        cin>>times[i];
        int a;cin>>a;
        while(a!=-1){
            v[a-1].push_back(i);
            ar[i]++;
            cin>>a;
        }
    }
    queue<int> q;
    for(int i=0;i<n;i++){
        if(!ar[i]){
            q.push(i);
            dp[i]=times[i];
        }
    }
    while(!q.empty()){
        int cur=q.front();q.pop();
        for(int i=0;i<v[cur].size();i++){
            dp[v[cur][i]]=max(dp[v[cur][i]], dp[cur]+times[v[cur][i]]);
            if(!--ar[v[cur][i]]){
                q.push(v[cur][i]);
            }
        }
    }
    for(int i=0;i<n;i++)cout<<dp[i]<<'\n';
    return 0;
}