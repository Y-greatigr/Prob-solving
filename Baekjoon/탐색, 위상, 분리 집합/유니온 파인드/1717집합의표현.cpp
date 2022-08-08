#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int parent[1'000'001];

int Find(int cur){
    if(cur==parent[cur])return cur;
    return parent[cur]=Find(parent[cur]);
}
void Union(int i, int j){
    i=Find(parent[i]);
    j=Find(parent[j]);
    if(i>j) parent[i]=j;
    else if(i<j) parent[j]=i;
}
int main(){
    FastIO;
    int n,m;cin>>n>>m;
    for(int i=0;i<=n;i++)parent[i]=i;
    while(m--){
        int b,c,d;cin>>b>>c>>d;
        if(!b)Union(c,d);
        else{
            if(Find(c)==Find(d))cout<<"YES"<<'\n';
            else cout<<"NO"<<'\n';
        }
    }
    return 0;
}