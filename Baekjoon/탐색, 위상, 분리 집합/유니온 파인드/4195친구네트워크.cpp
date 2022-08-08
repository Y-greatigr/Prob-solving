#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int parent[200'000], network[200'000];

int Find(int cur){
    if(cur==parent[cur])return cur;
    return parent[cur]=Find(parent[cur]);
}
int Union(int x, int y){
    x=Find(x), y= Find(y);
    if(x==y)return network[x];
    int a=x<y?x:y, b=x<y?y:x;
    parent[b]=a;
    network[a]+=network[b];
    return network[a];
}
int main(){
    FastIO;
    int t;cin>>t;
    while(t--){
        int f, ind=0;cin>>f;
        map<string, int> m;
        for(int i=0;i<2*f;i++){
            parent[i]=i;
            network[i]=1;
        }
        while(f--){
            string a,b;cin>>a>>b;
            if(m.find(a)==m.end())m[a]=ind++;
            if(m.find(b)==m.end())m[b]=ind++;
            cout<<Union(m[a], m[b])<<'\n';
        }
    }
    return 0;
}