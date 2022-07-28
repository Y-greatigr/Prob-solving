#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int parent[100'001];
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
int main(){
    FastIO;
    int g,p, cnt=0;cin>>g>>p;
    for(int i=1;i<=g;i++)parent[i]=i;
    while(p--){
        int i;cin>>i;
        i=Find(i);
        if(!i)break;
        else Union(i-1, i);
        cnt++;
    }
    cout<<cnt;
    return 0;
}