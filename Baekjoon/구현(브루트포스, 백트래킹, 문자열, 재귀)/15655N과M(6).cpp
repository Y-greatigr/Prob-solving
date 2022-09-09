#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

vector<int> v, ar;
void dfs(int cur, int ind, int n, int m){
    if(cur==m){
        for(auto i:v)cout<<i<<" ";
        cout<<'\n';
        return;
    }
    for(int i=ind;i<n;i++){
        v.push_back(ar[i]);
        dfs(cur+1, i+1, n, m);
        v.pop_back();
    }
}
int main(){
    FastIO;
    int n,m;cin>>n>>m;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        ar.push_back(a);
    }
    sort(ar.begin(),ar.end());
    dfs(0, 0, n, m);
    return 0;
}