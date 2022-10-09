#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

struct path{
    int y;
    int r;
};
int ar[1'001]={0,}, parent[1'001], score[1'001]={0,};
vector<path> v[1'001];
int main(){
    FastIO;
    int n,m;cin>>n>>m;
    while(m--){
        path d;
        int a; cin>>a>>d.y>>d.r;
        v[a].push_back(d);
        ar[d.y]++;
    }
    queue<int> q;q.push(1);
    while(!q.empty()){
        int cur=q.front();q.pop();
        for(int i=0;i<v[cur].size();i++){
            --ar[v[cur][i].y];
            if(score[v[cur][i].y]<score[cur]+v[cur][i].r){
                score[v[cur][i].y]=score[cur]+v[cur][i].r;
                parent[v[cur][i].y]=cur;
            }
            if(!ar[v[cur][i].y] && v[cur][i].y!=1){
                q.push(v[cur][i].y);
            }
        }
    }
    cout<<score[1]<<'\n'<<1<<" ";
    int k=1;
    vector<int> tmp;
    while(parent[k]!=1){
        k=parent[k];
        tmp.push_back(k);
    }
    reverse(tmp.begin(), tmp.end());
    for(auto i:tmp)cout<<i<<" ";
    cout<<1;
    return 0;
}