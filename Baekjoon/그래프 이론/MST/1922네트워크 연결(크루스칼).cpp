#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int parent[1'001];
vector<tuple<int,int,int>> v;
int Find(int cur){
    if(parent[cur]==cur)return cur;
    return parent[cur]=Find(parent[cur]);
}
void Union(int a, int b){
    a= Find(a);
    b=Find(b);
    if(a==b)return;
    if(a<b)parent[b]=a;
    else parent[a]=b;
}
bool cmp(tuple<int,int,int> a, tuple<int,int,int> b){
    return get<2>(a) < get<2>(b);
}
int main(){
    FastIO;
    int V,E, cnt=0, sum=0;cin>>V>>E;
    for(int i=1;i<=V;i++)parent[i]=i;
    for(int i=0;i<E;i++){
        int a,b,c;cin>>a>>b>>c;
        v.push_back({a,b,c});
    }
    sort(v.begin(), v.end(), cmp);
    for(int i=0;i<E;i++){
        auto[a,b,c]=v[i];
        a=Find(a), b=Find(b);
        if(a==b)continue;
        Union(a,b);
        sum+=c;
        cnt++;
        if(cnt==V-1)break;
    }
    cout<<sum;
    return 0;
}