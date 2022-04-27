#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int N,L,R, cnt=0;
int a[50][50];
bool visited[50][50]={false,};

bool bfs(int x, int y){
    vector<pair<int,int>> v;
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y]=true;
    while(!q.empty()){
        int cur_x=q.front().first;
        int cur_y=q.front().second;q.pop();
        for(int k=0;k<4;k++){
            int nx=cur_x+"1012"[k]-'1';
            int ny=cur_y+"2101"[k]-'1';
            if(nx<0 || nx>=N || ny<0 || ny>=N || visited[nx][ny] || abs(a[cur_x][cur_y]-a[nx][ny])<L || abs(a[cur_x][cur_y]-a[nx][ny])>R)continue;
            q.push({nx,ny});
            v.push_back({nx,ny});
            visited[nx][ny]=true;
        }
    }
    if(!v.size()) return true;
    int sum=a[x][y];
    for(int i=0;i<v.size();i++)sum+=a[v[i].first][v[i].second];
    sum/=(v.size()+1);a[x][y]=sum;
    for(int i=0;i<v.size();i++)a[v[i].first][v[i].second]=sum;
    return false;
}
int main(){
    FastIO;
    bool flag=true;
    cin>>N>>L>>R;
    for(int i=0;i<N;i++)for(int j=0;j<N;j++)cin>>a[i][j];
    do{
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(visited[i][j])continue;
                if(!bfs(i,j))flag=false;
            }
        }
        if(flag)break;
        cnt++;flag=true;
        memset(visited, false, sizeof(visited));
    }while(flag);
    cout<<cnt;
    return 0;
}