#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int parent[501];
bool is_tree[501];
int Find(int cur){
    if(parent[cur]==cur)return cur;
    return parent[cur]=Find(parent[cur]);
}
void Union(int a, int b){
    a=Find(a);
    b=Find(b);
    if(a==b)is_tree[a]=false;
    else if(a<b){
        if(!is_tree[b])is_tree[a]=false;
        parent[b]=a;
    }
    else {
        if(!is_tree[a])is_tree[b]=false;
        parent[a]=b;
    }
}
int main(){
    FastIO;
    int n,m, T=0;cin>>n>>m;
    while(n){
        T++;
        for(int i=1;i<=n;i++)parent[i]=i, is_tree[i]=true;
        int cnt=0;
        while(m--){
            int a,b;cin>>a>>b;
            Union(a,b);
        }
        for(int i=1;i<=n;i++){
            if(is_tree[Find(i)]){
                cnt++;
                is_tree[Find(i)]=false;
            }
        }
        if(!cnt)cout<<"Case "<<T<<": No trees.\n";
        else if(cnt==1)cout<<"Case "<<T<<": There is one tree.\n";
        else cout<<"Case "<<T<<": A forest of "<<cnt<<" trees.\n";
        cin>>n>>m;
    }
    return 0;
}