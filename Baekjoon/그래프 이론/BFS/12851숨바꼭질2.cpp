#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int a[100001][2]; // {시간, 중복 횟수}
bool visited[100001];
int main(){
    FastIO;
    memset(a, 0, sizeof(a));
    int n,k;cin>>n>>k;
    queue<pair<int,int>> q; // {위치, 시간}
    q.push({n,0});
    visited[n]=true;
    while(!q.empty()){
        auto cur=q.front();q.pop();
        if(a[k][0]>0 && cur.second>a[k][0])break;
        a[cur.first][1]++;
        int mi=cur.first-1;
        if(mi>=0 && visited[mi] && cur.second<a[mi][0]){
            a[mi][0]=cur.second+1;
            q.push({mi, cur.second+1});
        }
        else if(mi>=0 && !visited[mi]){
            a[mi][0]=cur.second+1;
            q.push({mi, cur.second+1});
            visited[mi]=true;
        }
        int pl=cur.first+1;
        if(pl<=100000 && visited[pl] && cur.second<a[pl][0]){
            a[pl][0]=cur.second+1;
            q.push({pl, cur.second+1});
        }
        else if(pl<=100000 && !visited[pl]){
            a[pl][0]=cur.second+1;
            q.push({pl, cur.second+1});
            visited[pl]=true;
        }
        int mu=cur.first*2;
        if(mu<=100000 && visited[mu] && cur.second<a[mu][0]){
            a[mu][0]=cur.second+1;
            q.push({mu, cur.second+1});
        }
        if(mu<=100000 && !visited[mu]){
            a[mu][0]=cur.second+1;
            q.push({mu, cur.second+1});
            visited[mu]=true;
        }

    }
    cout<<a[k][0]<<'\n'<<a[k][1];
    return 0;
}
