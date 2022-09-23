#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int ar[25][25];
int visited[25][25];
int visited2[25][25];
bool cmp(pair<int,int> a, pair<int,int> b){
    return ar[a.first][a.second]>ar[b.first][b.second];
}
int main(){
    FastIO;
    int N,M,T,D;cin>>N>>M>>T>>D;
    for(int i=0;i<N;i++)for(int j=0;j<M;j++){
        char c;cin>>c;
        if(c>='a')ar[i][j]=c-'a'+26;
        else ar[i][j]=c-'A';
        visited[i][j]=100'000'000;
    }
    queue<pair<int,int>>q;
    q.push({0,0});
    visited[0][0]=0;
    while(!q.empty()){
        auto [x,y]=q.front();q.pop();
        for(int k=0;k<4;k++){
            int nx=x+"1012"[k]-'1';
            int ny=y+"2101"[k]-'1';
            if(nx<0 || ny<0 || nx>=N || ny>=M
            || abs(ar[x][y]-ar[nx][ny])>T)continue;
            if(ar[nx][ny]<=ar[x][y] && visited[x][y]+1<visited[nx][ny]
            && visited[x][y]+1 <= D){
                visited[nx][ny]=visited[x][y]+1;
                q.push({nx,ny});
            }
            else if(ar[nx][ny]>ar[x][y]
            && visited[x][y]+pow(ar[nx][ny]-ar[x][y],2)<visited[nx][ny]
            && visited[x][y]+pow(ar[nx][ny]-ar[x][y],2) <= D){
                visited[nx][ny]=visited[x][y]+pow(ar[nx][ny]-ar[x][y],2);
                q.push({nx,ny});
            }
        }
    }
    vector<pair<int,int>> v;
    for(int i=0;i<N;i++)for(int j=0;j<M;j++){
        if(visited[i][j]>D)continue;
        v.push_back({i,j});
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<v.size();i++){
        auto [xx,yy]=v[i];
        for(int j=0;j<N;j++)fill(visited2[j],visited2[j]+M,100'000'000);
        visited2[xx][yy]=visited[xx][yy];
        q.push({xx,yy});
        while(!q.empty()){
            auto [x,y]=q.front();q.pop();
            for(int k=0;k<4;k++){
                int nx=x+"1012"[k]-'1';
                int ny=y+"2101"[k]-'1';
                if(nx<0 || ny<0 || nx>=N || ny>=M
                   || abs(ar[x][y]-ar[nx][ny])>T)continue;
                if(ar[nx][ny]<=ar[x][y] && visited2[x][y]+1<visited2[nx][ny]
                   && visited2[x][y]+1 <= D){
                    visited2[nx][ny]=visited2[x][y]+1;
                    q.push({nx,ny});
                }
                else if(ar[nx][ny]>ar[x][y]
                        && visited2[x][y]+pow(ar[nx][ny]-ar[x][y],2)<visited2[nx][ny]
                        && visited2[x][y]+pow(ar[nx][ny]-ar[x][y],2) <= D){
                    visited2[nx][ny]=visited2[x][y]+pow(ar[nx][ny]-ar[x][y],2);
                    q.push({nx,ny});
                }
            }
        }
        if(visited2[0][0]<=D){
            cout<<ar[xx][yy];
            return 0;
        }
    }
    return 0;
}