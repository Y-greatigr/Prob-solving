#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int ar[21][21]={0,}, tmp[21][21]={0,};
bool wall[21][21][21][21]={false,};
int R,C,K,W;
struct Point{
    int x,y, d;
};
struct survey{
    int x,y;
};
vector<Point> v;
vector<survey> sur;
bool check(){
    for(int i=0;i<sur.size();i++){
        if(ar[sur[i].x][sur[i].y]<K){
            return true;
        }
    }
    return false;
}
void clean(int div){
    for(int i=1;i<=R;i++)for(int j=1;j<=C;j++){
        ar[i][j]+=(tmp[i][j]/div);
        if(ar[i][j]<0)ar[i][j]=0;
        tmp[i][j]=0;
    }
}
void wind_right(int cur, int x, int y){
    if(cur==1){
        tmp[x][y]=cur;
        return;
    }
    tmp[x][y]=cur;
    if(x-1>0 && y+1<=C && !wall[x][y][x-1][y] && !wall[x-1][y][x-1][y+1])wind_right(cur-1,x-1,y+1);
    if(y+1<=C && !wall[x][y][x][y+1])wind_right(cur-1,x,y+1);
    if(x+1<=R && y+1<=C && !wall[x][y][x+1][y] && !wall[x+1][y][x+1][y+1])wind_right(cur-1,x+1,y+1);
}
void wind_up(int cur, int x, int y){
    if(cur==1){
        tmp[x][y]=cur;
        return;
    }
    tmp[x][y]=cur;
    if(x-1>0 && y+1<=C && !wall[x][y][x][y+1] && !wall[x][y+1][x-1][y+1])wind_up(cur-1,x-1,y+1);
    if(x-1>0 && !wall[x][y][x-1][y])wind_up(cur-1,x-1,y);
    if(x-1>0 && y-1>0 && !wall[x][y][x][y-1] && !wall[x][y-1][x-1][y-1])wind_up(cur-1,x-1,y-1);
}
void wind_left(int cur, int x, int y){
    if(cur==1){
        tmp[x][y]=cur;
        return;
    }
    tmp[x][y]=cur;
    if(x-1>0 && y-1>0 && !wall[x][y][x-1][y] && !wall[x-1][y][x-1][y-1])wind_left(cur-1,x-1,y-1);
    if(y-1>0 && !wall[x][y][x][y-1])wind_left(cur-1,x,y-1);
    if(x+1<=R && y-1>0 && !wall[x][y][x+1][y] && !wall[x+1][y][x+1][y-1])wind_left(cur-1,x+1,y-1);
}
void wind_down(int cur, int x, int y){
    if(cur==1){
        tmp[x][y]=cur;
        return;
    }
    tmp[x][y]=cur;
    if(x+1<=R && y+1<=C && !wall[x][y][x][y+1] && !wall[x][y+1][x+1][y+1])wind_down(cur-1,x+1,y+1);
    if(x+1<=R && !wall[x][y][x+1][y])wind_down(cur-1,x+1,y);
    if(x+1<=R && y-1>0 && !wall[x][y][x][y-1] && !wall[x][y-1][x+1][y-1])wind_down(cur-1,x+1,y-1);
}
void wind(){
    for(int i=0;i<v.size();i++){
        if(v[i].d==0){
            if(v[i].y+1<=C && !wall[v[i].x][v[i].y][v[i].x][v[i].y+1]){
                wind_right(5, v[i].x, v[i].y+1);
            }
        }
        else if(v[i].d==1){
            if(v[i].x-1>0 && !wall[v[i].x][v[i].y][v[i].x-1][v[i].y]){
                wind_up(5, v[i].x-1, v[i].y);
            }
        }
        else if(v[i].d==2){
            if(v[i].y-1>0 && !wall[v[i].x][v[i].y][v[i].x][v[i].y-1]){
                wind_left(5, v[i].x, v[i].y-1);
            }
        }
        else if(v[i].d==3){
            if(v[i].x+1<=R && !wall[v[i].x][v[i].y][v[i].x+1][v[i].y]){
                wind_down(5, v[i].x+1, v[i].y);
            }
        }
        clean(1);
    }
}
void regulate(){
    for(int i=1;i<=R;i++)for(int j=1;j<=C;j++){
        for(int k=0;k<4;k++){
            int nx=i+"1012"[k]-'1';
            int ny=j+"2101"[k]-'1';
            if(nx<1 || ny<1 || nx>R || ny>C
            || wall[i][j][nx][ny])
                continue;
            tmp[i][j]-=(ar[i][j]-ar[nx][ny])/4;
            tmp[nx][ny]+=(ar[i][j]-ar[nx][ny])/4;
        }
    }
    clean(2);
}
void minus_temp(){
    for(int i=2;i<=R-1;i++){
        if(ar[i][1])ar[i][1]--;
        if(ar[i][C])ar[i][C]--;
    }
    for(int j=1;j<=C;j++){
        if(ar[1][j])ar[1][j]--;
        if(ar[R][j])ar[R][j]--;
    }
}
int main(){
    FastIO;
    int cnt=0;
    cin>>R>>C>>K;
    for(int i=1;i<=R;i++)for(int j=1;j<=C;j++){
        int a;cin>>a;
        if(a==5){
            survey s;
            s.x=i, s.y=j;
            sur.push_back(s);
        }
        else if(a){
            Point p;
            if(a==1)p.d=0;
            else if(a==2)p.d=2;
            else if(a==3)p.d=1;
            else if(a==4)p.d=3;
            p.x=i,p.y=j;
            v.push_back(p);
        }
    }
    cin>>W;
    for(int i=0;i<W;i++){
        int a,b,c;cin>>a>>b>>c;
        if(!c){
            wall[a][b][a-1][b]=true;
            wall[a-1][b][a][b]=true;
        }
        else{
            wall[a][b][a][b+1]=true;
            wall[a][b+1][a][b]=true;
        }
    }
    while(cnt<=100){
        if(!check()){
            cout<<cnt;
            return 0;
        }
        wind();
        regulate();
        minus_temp();
        cnt++;
    }
    cout<<101;
    return 0;
}