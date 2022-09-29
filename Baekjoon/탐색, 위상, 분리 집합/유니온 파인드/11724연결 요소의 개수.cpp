#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int parent[1'001];
bool visited[1'001]={false,};
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
int main(){
    FastIO;
    int n,m,cnt=0;cin>>n>>m;
    for(int i=1;i<=n;i++)parent[i]=i;
    while(m--){
        int a,b;cin>>a>>b;
        Union(a,b);
    }
    for(int i=1;i<=n;i++){
        if(visited[Find(i)])continue;
        visited[Find(i)]=true;
        cnt++;
    }
    cout<<cnt;
    return 0;
}