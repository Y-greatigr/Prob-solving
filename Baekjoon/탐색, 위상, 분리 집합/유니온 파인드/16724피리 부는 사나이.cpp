#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int n,m;
char ar[1000][1000];
int parent[1'000'000];
bool visited[1'000'000]={false, };
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
    int cnt=0;
    cin>>n>>m;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++){
        cin>>ar[i][j];
        parent[i*1000+j]=i*1000+j;
    }
    for(int i=0;i<n;i++)for(int j=0;j<m;j++){
        int nx,ny;
        if(ar[i][j]=='L')nx=i, ny=j-1;
        else if(ar[i][j]=='R')nx=i,ny=j+1;
        else if(ar[i][j]=='U')nx=i-1,ny=j;
        else if(ar[i][j]=='D')nx=i+1,ny=j;
        if(nx<0 || ny<0 || nx>=n || ny>=m){
            continue;
        }
        Union(i*1000+j, nx*1000+ny);
    }
    for(int i=0;i<n;i++)for(int j=0;j<m;j++){
        int k=Find(i*1000+j);
        if(!visited[k]){
            cnt++;
            visited[k]=true;
        }
    }
    cout<<cnt;
    return 0;
}