#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

bool visited[301][301]={false, };
int main(){
    FastIO;
    int t;cin>>t;
    while(t--){
        memset(visited, false, sizeof(visited));
        int L, st_x, st_y, des_x, des_y;cin>>L>>st_x>>st_y>>des_x>>des_y;
        if(st_x==des_x && st_y==des_y)cout<<0<<'\n';
        queue<pair<pair<int,int>, int>> q;
        q.push({{st_x, st_y}, 0});
        visited[st_x][st_y]= true;
        bool flag=true;
        while(!q.empty()){
            auto cur=q.front();q.pop();
            for(int i=0;i<8;i++){
                int nx=cur.first.first+"10013443"[i]-'2';
                int ny=cur.first.second+"43100134"[i]-'2';
                if(nx<0 || nx>=L || ny<0 || ny>=L || visited[nx][ny])continue;
                if(nx==des_x && ny==des_y){
                    cout<<cur.second+1<<'\n';
                    flag= false;break;
                }
                visited[nx][ny]=true;
                q.push({{nx,ny},cur.second+1});
            }
            if(!flag)break;
        }
    }
    return 0;
}