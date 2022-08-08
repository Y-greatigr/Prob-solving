#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int N,M, mini=INT_MAX;
vector<tuple<int,int,int>> v;
int ar[50][50];

void dfs(int cur, int cnt){
    if(cnt==M){ // bfs
        queue<pair<int,int>> q;
        int visited[50][50]={0, }, maxi=0;
        int initial[50][50]={0, };
        for(int i=0;i<v.size();i++){
            if(get<2>(v[i])){
                q.push({get<0>(v[i]), get<1>(v[i])});
                initial[get<0>(v[i])][get<1>(v[i])]=1;
            }
        }
        while(!q.empty()){
            auto c=q.front();q.pop();
            for(int i=0;i<4;i++){
                int nx=c.first+"1012"[i]-'1';
                int ny=c.second+"2101"[i]-'1';
                if(nx<0 ||ny<0 || nx>=N || ny>=N || visited[nx][ny] || ar[nx][ny]==1 || initial[nx][ny])continue;
                visited[nx][ny]=visited[c.first][c.second]+1;
                q.push({nx,ny});
            }
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(ar[i][j])continue;
                if(!visited[i][j]) return;
                maxi=max(visited[i][j], maxi);
            }
        }
        mini=min(maxi, mini);
        return;
    }
    for(int i=cur;i<v.size();i++){
        if(get<2>(v[i]))continue;
        get<2>(v[i])=1;
        dfs(i+1, cnt+1);
        get<2>(v[i])=0;
    }
}
int main(){
    FastIO;
    cin>>N>>M;
    bool flag=false;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>ar[i][j];
            if(ar[i][j]==2)v.push_back({i,j, 0});
            if(!ar[i][j])flag= true;
        }
    }
    dfs(0, 0);
    if(!flag)cout<<0;
    else cout<<(mini==INT_MAX?-1:mini);
    return 0;
}