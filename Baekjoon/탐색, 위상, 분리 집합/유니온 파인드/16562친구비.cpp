#include <bits/stdc++.h>

using namespace std;

int ar[10'001], parent[10'001], visited[10'001]={0,};
int Find(int cur){
    if(parent[cur]==cur)return cur;
    return parent[cur]=Find(parent[cur]);
}
void Union(int a, int b){
    a=Find(a);
    b=Find(b);
    if(a==b)return;
    if(a<b){
        parent[b]=a;
        ar[a]=min(ar[a],ar[b]);
    }
    else {
        parent[a]=b;
        ar[b]=min(ar[a],ar[b]);
    }
}
int main(){
    int n,m,k, mini=0;cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        cin>>ar[i];
        parent[i]=i;
    }
    while(m--){
        int a,b;cin>>a>>b;
        Union(a,b);
    }
    for(int i=1;i<=n;i++){
        if(visited[Find(i)])continue;
        visited[Find(i)]=1;
        mini+=ar[Find(i)];
    }
    if(mini>k)cout<<"Oh no";
    else cout<<mini;
    return 0;
}