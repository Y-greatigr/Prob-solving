#include <bits/stdc++.h>

using namespace std;

int parent[1000];
int Find(int cur){
    if(parent[cur]==cur)return cur;
    return parent[cur]=Find(parent[cur]);
}
void Union(int a, int b){
    a=Find(a);
    b=Find(b);
    if(a==b)return;
    if(a<b)parent[b]=a;
    else parent[a]=b;
}
bool cmp(tuple<int,int,int> a, tuple<int,int,int> b){
    return get<2>(a)>get<2>(b);
}
int main(){
    int p,w,c,v;cin>>p>>w>>c>>v;
    for(int i=0;i<p;i++)parent[i]=i;
    vector<tuple<int,int,int>> vec;
    while(w--){
        int a,b,d;cin>>a>>b>>d;
        vec.push_back({a,b,d});
    }
    sort(vec.begin(),vec.end(), cmp);
    for(int i=0;i<vec.size();i++){
        auto [x,y,width]=vec[i];
        Union(x,y);
        if(Find(c)==Find(v)){
            cout<<width;
            return 0;
        }
    }
    return 0;
}