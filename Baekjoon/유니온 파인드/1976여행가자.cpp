#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

vector<int> parent(200);
int Find(int cur){
    if(parent[cur]==cur)return cur;
    return parent[cur]=Find(parent[cur]);
}
void Union(int x, int y){
    x=Find(x);
    y=Find(y);
    if(x>y)parent[x]=y;
    else parent[y]=x;
}
int main(){
    FastIO;
    int n,m;cin>>n>>m;
    for(int i=0;i<n;i++)parent[i]=i;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++){
        int k;cin>>k;
        if(k)Union(i,j);
    }
    int tmp;cin>>tmp;
    int x=Find(tmp-1);
    for(int i=1;i<m;i++){
        cin>>tmp;
        int y=Find(tmp-1);
        if(x!=y){cout<<"NO";return 0;}
        x=y;
    }
    cout<<"YES";
    return 0;

}