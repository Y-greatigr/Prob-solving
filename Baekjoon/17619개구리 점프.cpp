#include <bits/stdc++.h>

using namespace std;

int n,q;
vector<tuple<int,int,int>> v;
int parent[100'001]={0,};

int Find(int cur){
    if(parent[cur]==cur) return cur;
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
    return get<0>(a)<get<0>(b);
}
int main(){
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        parent[i]=i;
        int a,b,c;cin>>a>>b>>c;
        v.push_back({a,b,i});
    }
    sort(v.begin(), v.end(), cmp);
    for(int i=0, j=1;i<n && j<n;){
        if(get<0>(v[j])<=get<1>(v[i])){
            Union(get<2>(v[i]), get<2>(v[j]));
            j++;
        }
        else i++;
    }
    for(int i=0;i<q;i++){
        int a,b;cin>>a>>b;
        if(Find(a)==Find(b))cout<<1<<'\n';
        else cout<<0<<'\n';
    }
    return 0;
}