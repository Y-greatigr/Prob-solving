#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int n,m, hole_x, hole_y;
char ar[10][10];
struct Point{
    int r_x, r_y, b_x, b_y, cnt;
};
queue<Point> q;
bool moving_right(Point p){
    int r_j, b_j;
    if(p.r_x==p.b_x){
        if(p.r_y<p.b_y){
            for(b_j=p.b_y;b_j<m-1;b_j++){
                if(ar[p.b_x][b_j+1]=='O')return false;
                if(ar[p.b_x][b_j+1]=='#')break;
            }
            for(r_j=p.r_y;r_j<m-1;r_j++){
                if(ar[p.r_x][r_j+1]=='O')return true;
                if(ar[p.r_x][r_j+1]=='#' || r_j+1==b_j)break;
            }
        }
        else{
            bool flag=false;
            for(r_j=p.r_y;r_j<m-1;r_j++){
                if(ar[p.r_x][r_j+1]=='O')flag=true;
                if(ar[p.r_x][r_j+1]=='#')break;
            }
            for(b_j=p.b_y;b_j<m-1;b_j++){
                if(ar[p.b_x][b_j+1]=='O')return false;
                if(ar[p.b_x][b_j+1]=='#' || b_j+1==r_j)break;
            }
            if(flag)return true;
        }
    }
    else{
        for(b_j=p.b_y;b_j<m-1;b_j++){
            if(ar[p.b_x][b_j+1]=='O')return false;
            if(ar[p.b_x][b_j+1]=='#')break;
        }
        for(r_j=p.r_y;r_j<m-1;r_j++){
            if(ar[p.r_x][r_j+1]=='O')return true;
            if(ar[p.r_x][r_j+1]=='#')break;
        }
    }
    if(p.cnt>=10 || (p.r_y==r_j && p.b_y==b_j))return false;
    p.r_y=r_j, p.b_y=b_j, p.cnt++;
    q.push(p);
    return false;
}
bool moving_left(Point p){
    int r_j, b_j;
    if(p.r_x==p.b_x){
        if(p.r_y>p.b_y){
            for(b_j=p.b_y;b_j>0;b_j--){
                if(ar[p.b_x][b_j-1]=='O')return false;
                if(ar[p.b_x][b_j-1]=='#')break;
            }
            for(r_j=p.r_y;r_j>0;r_j--){
                if(ar[p.r_x][r_j-1]=='O')return true;
                if(ar[p.r_x][r_j-1]=='#' || r_j-1==b_j)break;
            }
        }
        else{
            bool flag=false;
            for(r_j=p.r_y;r_j>0;r_j--){
                if(ar[p.r_x][r_j-1]=='O')flag=true;
                if(ar[p.r_x][r_j-1]=='#')break;
            }
            for(b_j=p.b_y;b_j>0;b_j--){
                if(ar[p.b_x][b_j-1]=='O')return false;
                if(ar[p.b_x][b_j-1]=='#' || b_j-1==r_j)break;
            }
            if(flag)return true;
        }
    }
    else{
        for(b_j=p.b_y;b_j>0;b_j--){
            if(ar[p.b_x][b_j-1]=='O')return false;
            if(ar[p.b_x][b_j-1]=='#')break;
        }
        for(r_j=p.r_y;r_j>0;r_j--){
            if(ar[p.r_x][r_j-1]=='O')return true;
            if(ar[p.r_x][r_j-1]=='#')break;
        }
    }
    if(p.cnt>=10 || (p.r_y==r_j && p.b_y==b_j))return false;
    p.r_y=r_j, p.b_y=b_j, p.cnt++;
    q.push(p);
    return false;
}
bool moving_up(Point p){
    int r_j, b_j;
    if(p.r_y==p.b_y){
        if(p.r_x>p.b_x){
            for(b_j=p.b_x;b_j>0;b_j--){
                if(ar[b_j-1][p.b_y]=='O')return false;
                if(ar[b_j-1][p.b_y]=='#')break;
            }
            for(r_j=p.r_x;r_j>0;r_j--){
                if(ar[r_j-1][p.r_y]=='O')return true;
                if(ar[r_j-1][p.r_y]=='#' || r_j-1==b_j)break;
            }
        }
        else{
            bool flag=false;
            for(r_j=p.r_x;r_j>0;r_j--){
                if(ar[r_j-1][p.r_y]=='O')flag=true;
                if(ar[r_j-1][p.r_y]=='#')break;
            }
            for(b_j=p.b_x;b_j>0;b_j--){
                if(ar[b_j-1][p.b_y]=='O')return false;
                if(ar[b_j-1][p.b_y]=='#' || b_j-1==r_j)break;
            }
            if(flag)return true;
        }
    }
    else{
        for(b_j=p.b_x;b_j>0;b_j--){
            if(ar[b_j-1][p.b_y]=='O')return false;
            if(ar[b_j-1][p.b_y]=='#')break;
        }
        for(r_j=p.r_x;r_j>0;r_j--){
            if(ar[r_j-1][p.r_y]=='O')return true;
            if(ar[r_j-1][p.r_y]=='#')break;
        }
    }
    if(p.cnt>=10 || (p.r_x==r_j && p.b_x==b_j))return false;
    p.r_x=r_j, p.b_x=b_j, p.cnt++;
    q.push(p);
    return false;
}
bool moving_down(Point p){
    int r_j, b_j;
    if(p.r_y==p.b_y){
        if(p.r_x<p.b_x){
            for(b_j=p.b_x;b_j<n-1;b_j++){
                if(ar[b_j+1][p.b_y]=='O')return false;
                if(ar[b_j+1][p.b_y]=='#')break;
            }
            for(r_j=p.r_x;r_j<n-1;r_j++){
                if(ar[r_j+1][p.r_y]=='O')return true;
                if(ar[r_j+1][p.r_y]=='#' || r_j+1==b_j)break;
            }
        }
        else{
            bool flag=false;
            for(r_j=p.r_x;r_j<n-1;r_j++){
                if(ar[r_j+1][p.r_y]=='O')flag=true;
                if(ar[r_j+1][p.r_y]=='#')break;
            }
            for(b_j=p.b_x;b_j<n-1;b_j++){
                if(ar[b_j+1][p.b_y]=='O')return false;
                if(ar[b_j+1][p.b_y]=='#' || b_j+1==r_j)break;
            }
            if(flag)return true;
        }
    }
    else{
        for(b_j=p.b_x;b_j<n-1;b_j++){
            if(ar[b_j+1][p.b_y]=='O')return false;
            if(ar[b_j+1][p.b_y]=='#')break;
        }
        for(r_j=p.r_x;r_j<n-1;r_j++){
            if(ar[r_j+1][p.r_y]=='O')return true;
            if(ar[r_j+1][p.r_y]=='#')break;
        }
    }
    if(p.cnt>=10 || (p.r_x==r_j && p.b_x==b_j))return false;
    p.r_x=r_j, p.b_x=b_j, p.cnt++;
    q.push(p);
    return false;
}
int main(){
    FastIO;
    cin>>n>>m;
    Point p;p.cnt=1;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++){
        cin>>ar[i][j];
        if(ar[i][j]=='O')hole_x=i,hole_y=j;
        else if(ar[i][j]=='R')p.r_x=i,p.r_y=j;
        else if(ar[i][j]=='B')p.b_x=i,p.b_y=j;
    }
    q.push(p);
    while(!q.empty()){
        Point point=q.front();q.pop();
        for(int k=0;k<4;k++){
            if(k==0 && moving_right(point)){
                cout<<point.cnt;
                return 0;
            }
            else if(k==1 &&moving_up(point)){
                cout<<point.cnt;
                return 0;
            }
            else if(k==2 && moving_left(point)){
                cout<<point.cnt;
                return 0;
            }
            else if(k==3 && moving_down(point)){
                cout<<point.cnt;
                return 0;
            }
        }
    }
    cout<<-1;
    return 0;
}