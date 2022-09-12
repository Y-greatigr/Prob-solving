#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

char ar[250][250];
bool visited[250][250]={false,};
int main(){
    FastIO;
    int r,c, sheep=0, wolf=0;cin>>r>>c;
    vector<pair<int,int>> v;
    for(int i=0;i<r;i++)for(int j=0;j<c;j++){
        cin>>ar[i][j];
        if(ar[i][j]=='o'){
            v.push_back({i,j});
            sheep++;
        }
        else if(ar[i][j]=='v')wolf++;
    }
    for(int i=0;i<v.size();i++){
        auto [x,y]=v[i];
        if(visited[x][y])continue;
        visited[x][y]=true;
        int sheep_cnt=1, wolf_cnt=0;
        queue<pair<int,int>> q;
        q.push({x,y});
        while(!q.empty()){
            auto [cx,cy]=q.front();q.pop();
            for(int k=0;k<4;k++){
                int nx=cx+"1012"[k]-'1';
                int ny=cy+"2101"[k]-'1';
                if(nx<0 || ny<0 || nx>=r || ny>=c
                || ar[nx][ny]=='#' || visited[nx][ny])
                    continue;
                if(ar[nx][ny]=='v')wolf_cnt++;
                else if(ar[nx][ny]=='o')sheep_cnt++;
                visited[nx][ny]=true;
                q.push({nx,ny});
            }
        }
        if(sheep_cnt>wolf_cnt)wolf-=wolf_cnt;
        else sheep-=sheep_cnt;
    }
    cout<<sheep<<" "<<wolf;
    return 0;
}