#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

pair<int,int> ar[1'000'001];
void dfs(int cur, int n){
    if(cur==n){
        cout<<cur<<" ";
        return;
    }
    dfs(ar[cur].second, n);
    cout<<cur<<" ";
}
int main(){
    FastIO;
    int n;cin>>n;
    ar[n]={0,n};
    for(int i=1;i<n;i++)ar[i]={INT_MAX/2,INT_MAX/2};
    queue<int> q;
    q.push(n);
    while(!q.empty()){
        int k=q.front();q.pop();
        if(k==1)break;
        if(k%3==0 && ar[k].first+1<ar[k/3].first){
            ar[k/3].first=ar[k].first+1;
            ar[k/3].second=k;
            q.push(k/3);
        }
        if(k%2==0 && ar[k].first+1<ar[k/2].first){
            ar[k/2].first=ar[k].first+1;
            ar[k/2].second=k;
            q.push(k/2);
        }
        if(ar[k].first+1<ar[k-1].first){
            ar[k-1].first=ar[k].first+1;
            ar[k-1].second=k;
            q.push(k-1);
        }
    }
    cout<<ar[1].first<<'\n';
    dfs(1, n);
    return 0;
}