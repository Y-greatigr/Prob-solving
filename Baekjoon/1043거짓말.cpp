#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int parent[51];
vector<int> v;
vector<int> party[51];
int Find(int x){
    if(parent[x]==x)return x;
    return Find(parent[x]);
}
void Union(int x, int y){
    x=Find(x);
    y=Find(y);
    parent[x]=y;
}
int main(){
    FastIO;
    int N,M,K;cin>>N>>M>>K;
    for(int i=1;i<=N;i++)parent[i]=i;
    for(int i=0;i<K;i++){
        int tmp;cin>>tmp;
        v.push_back(tmp);
    }
    for(int i=0;i<M;i++){
        int tmp, pre, cur=0; cin>>tmp;
        for(int j=0;j<tmp;j++){
            pre=cur;
            cin>>cur;
            if(j>0) Union(pre, cur);
            party[i].push_back(cur);
        }
    }
    for(auto x:party){
        int flag=0;
        for(auto y:x){
            if(flag)break;
            for(auto z:v){
                if(Find(y)==Find(z)){
                    flag=1; break;
                }
            }
        }
        if(flag)M--;
    }
    cout<<M;
    return 0;
}
