#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int ar[25][25];
int visited[25][25];
int visited2[25][25];

void input(int N,int M){
    for(int i=0;i<N;i++)for(int j=0;j<M;j++){
        char c;cin>>c;
        if(c>='a')ar[i][j]=c-'a'+26;
        else ar[i][j]=c-'A';
        visited[i][j]=100'000'000;
    }
}
bool cmp(pair<int,int> a, pair<int,int> b){
    return ar[a.first][a.second]>ar[b.first][b.second];
}
bool check_array(int x, int y, int nx, int ny, int N, int M, int T){
    return nx<0 || ny<0 || nx>=N || ny>=M || abs(ar[x][y]-ar[nx][ny])>T;
}
int plus_pow(int checked[][25], int x, int y, int nx, int ny){
    return checked[x][y]+pow(ar[nx][ny]-ar[x][y],2);
}
bool lower_equal(int checked[][25], int x, int y, int nx, int ny, int D){
    return ar[nx][ny]<=ar[x][y]
    && checked[x][y]+1<checked[nx][ny]
    && checked[x][y]+1 <= D;
}
bool higher(int checked[][25], int x, int y, int nx, int ny, int D){
    return ar[nx][ny]>ar[x][y]
    && plus_pow(checked, x,y,nx,ny)<checked[nx][ny]
    && plus_pow(checked, x,y,nx,ny) <= D;
}
void insert_queue(int checked[][25], int nx, int ny, int next, queue<pair<int,int>>& q){
    checked[nx][ny]=next;
    q.push({nx,ny});
}
void bfs(int N, int M, int T, int D, int i, int j, int checked[][25]){
    queue<pair<int,int>>q;
    q.push({i,j});
    while(!q.empty()){
        auto [x,y]=q.front();q.pop();
        for(int k=0;k<4;k++){
            int nx=x+"1012"[k]-'1';
            int ny=y+"2101"[k]-'1';
            if(check_array(x,y,nx,ny,N,M,T))continue;
            if(lower_equal(checked, x,y,nx,ny, D))
                insert_queue(checked,nx,ny, checked[x][y]+1, q);
            else if(higher(checked, x,y,nx,ny, D))
                insert_queue(checked,nx,ny, plus_pow(checked, x,y,nx,ny), q);
        }
    }
}
void accum_v(int N,int M,int D, vector<pair<int,int>> & v){
    for(int i=0;i<N;i++)for(int j=0;j<M;j++){
        if(visited[i][j]>D)continue;
        v.push_back({i,j});
    }
}
void mountain_to_hotel(int N, int M, int T, int D, vector<pair<int,int>> & v){
    for(int i=0;i<v.size();i++){
        auto [xx,yy]=v[i];
        for(int j=0;j<N;j++)fill(visited2[j],visited2[j]+M,100'000'000);
        visited2[xx][yy]=visited[xx][yy];
        bfs(N,M,T,D, xx, yy, visited2);   // 산->호텔
        if(visited2[0][0]<=D){
            cout<<ar[xx][yy];
            break;
        }
    }
}
int main(){
    FastIO;
    int N,M,T,D;cin>>N>>M>>T>>D;
    vector<pair<int,int>> v;

    input(N,M);

    visited[0][0]=0;
    bfs(N, M, T, D, 0, 0, visited); // 호텔->산

    accum_v(N,M,D,v);
    sort(v.begin(),v.end(),cmp); // 최대 높이 순서대로 담기

    mountain_to_hotel(N, M, T, D, v);   // 산->호텔

    return 0;
}