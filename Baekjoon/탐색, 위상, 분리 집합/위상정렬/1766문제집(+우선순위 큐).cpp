#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int N,M;
int ar[32'001]={0,};
vector<int> v[32'001];
int main(){
    FastIO;
    cin>>N>>M;
    for(int i=0;i<M;i++){
        int a,b;cin>>a>>b;
        ar[b]++;
        v[a].push_back(b);
    }
    priority_queue<int, vector<int>, greater<>> pq;
    for(int i=1;i<=N;i++){
        if(!ar[i])pq.push(i);
        sort(v[i].begin(), v[i].end());
    }
    while(!pq.empty()){
        int cur=pq.top();pq.pop();
        cout<<cur<<" ";
        for(int i=0;i<v[cur].size();i++){
            if(!--ar[v[cur][i]]){
                pq.push(v[cur][i]);
            }
        }
    }
    return 0;
}