#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
vector<string> v;

void dfs(int cur, string s, int n){
    if(cur==n){
        v.push_back(s);
        return;
    }
    for(int i=1;i<=3;i++){
        if(cur+i>n)break;
        dfs(cur+i, s+"+"+ to_string(i), n);
    }
}
int main(){
    FastIO;
    int n,k;cin>>n>>k;
    for(int i=1;i<=3;i++){
        dfs(i, to_string(i), n);
    }
    if(v.size()>=k) cout<<v[k-1];
    else cout<<-1;
    return 0;
}