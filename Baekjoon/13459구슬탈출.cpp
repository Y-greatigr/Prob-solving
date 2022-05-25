#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

char ar[10][10]={0,};
bool visited[10][10][10][10]={false, };
int main(){
    FastIO;
    int N,M, red_x, red_y, blue_x, blue_y, O_x, O_y;cin>>N>>M;
    queue<tuple<int,int,int, int, int>>q; // x, y, cnt, blue_x, blue_y
    for(int i=0;i<N;i++)for(int j=0;j<M;j++){
        cin>>ar[i][j];
        if(ar[i][j]=='R')red_x=i,red_y=j;
        else if(ar[i][j]=='B')blue_x=i, blue_y=j;
        else if(ar[i][j]=='O')O_x=i,O_y=j;
    }
    q.push({red_x, red_y, 0, blue_x, blue_y});
    visited[red_x][red_y][blue_x][blue_y]= true;
    while(!q.empty()){
        int rx=get<0>(q.front()), ry=get<1>(q.front()), cnt=get<2>(q.front()),
                bx=get<3>(q.front()), by=get<4>(q.front());q.pop();
        for(int i=0;i<4;i++){
            int nx=rx, ny=ry, bbx=bx, bby=by;
            bool flag1=false, flag2= false;
            while(true){
                if(ar[nx+"1012"[i]-'1'][ny+"2101"[i]-'1']=='#')break;
                nx+="1012"[i]-'1', ny+="2101"[i]-'1';
                if(nx==O_x && ny==O_y)flag1=true;
            }
            while(true){
                if(ar[bbx+"1012"[i]-'1'][bby+"2101"[i]-'1']=='#')break;
                bbx+="1012"[i]-'1', bby+="2101"[i]-'1';
                if(bbx==O_x && bby==O_y){flag2=true;break;}
            }
            if(flag2)continue;
            if(flag1){cout<<1;return 0;}
            if(nx==bbx && ny==bby){
                if(i==0){
                    if(ry>by)bby--;
                    else ny--;
                }
                else if(i==1){
                    if(rx>bx)nx++;
                    else bbx++;
                }
                else if(i==2){
                    if(ry>by)ny++;
                    else bby++;
                }
                else{
                    if(rx>bx)bbx--;
                    else nx--;
                }
            }
            if(visited[nx][ny][bbx][bby])continue;
            if(cnt!=9)q.push({nx,ny,cnt+1, bbx, bby});
            visited[nx][ny][bbx][bby]= true;
        }
    }
    cout<<0;
    return 0;
}