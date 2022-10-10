#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

int n,k, min_ele;
int ar[100]={0,};
int tmp[100][100]={0,};
int tmp2[100][100]={0,};
struct Point{
    int x,y;
};
queue<Point> q;
bool check(){
    int mini=1'000'000'000, maxi=0;
    for(int i=0;i<n;i++)mini=min(mini,ar[i]), maxi=max(maxi,ar[i]);
    min_ele=mini;
    if(abs(maxi-mini)<=k)return true;
    return false;
}
void plus_fish(){
    for(int i=0;i<n;i++){
        if(ar[i]==min_ele)ar[i]++;
    }
}
void insert_queue(int ii, int ii_max, int jj, int jj_max){
    for(int i=ii;i<ii_max;i++)for(int j=jj;j<jj_max;j++){
        if(tmp[i][j]){
            Point point;
            point.x=i, point.y=j;
            q.push(point);
        }
    }
}
void distribute_fish(){
    int num=q.size();
    while(num--){
        Point point=q.front();q.pop();
        for(int w=0;w<4;w++){
            int nx=point.x+"1012"[w]-'1';
            int ny=point.y+"2101"[w]-'1';
            if(nx<0 || ny<0 || nx>=n || ny>=n
               || !tmp[nx][ny])continue;
            if(tmp[point.x][point.y]>tmp[nx][ny]){
                tmp2[point.x][point.y]-=(tmp[point.x][point.y]-tmp[nx][ny])/5;
                tmp2[nx][ny]+=(tmp[point.x][point.y]-tmp[nx][ny])/5;
            }
        }
        q.push(point);
    }
    while(!q.empty()){
        Point point=q.front();q.pop();
        tmp[point.x][point.y]+=tmp2[point.x][point.y];
        tmp2[point.x][point.y]=0;
    }
}
void flattening(int ii, int ii_max, int jj, int jj_max){
    int ind=0;
    for(int j=jj;j<jj_max;j++)for(int i=ii;i<ii_max;i++){
        if(tmp[i][j]){
            ar[ind]=tmp[i][j];
            ind++;
            tmp[i][j]=0;
        }
    }
}
void copyy(){
    for(int i=0;i<n;i++)tmp[0][i]=ar[i];
}
void moving(){
    int len=n, row_min=0, row_max=0, col_min=0, col_max=0;
    copyy();
    while(len-(col_max-col_min+1)>=(row_max-row_min+1)){
        for(int j=col_max;j>=col_min;j--){
            for(int i=row_min;i<=row_max;i++){
                tmp[1+(col_max-j)][col_max+1+i]=tmp[i][j];
                tmp[i][j]=0;
            }
        }
        len-=(col_max-col_min+1);
        int temp=row_max;
        row_max=1+col_max-col_min;
        col_min+=(col_max-col_min)+1;
        col_max=col_min+temp;
    }
    insert_queue(0, row_max+1, col_min, col_min+len);
    distribute_fish();
    flattening(0, row_max+1, col_min, col_min+len);
    copyy();
    for(int i=0;i<n/2;i++){
        tmp[1][i+n/2]=tmp[0][n/2-i-1];
        tmp[0][n/2-i-1]=0;
    }
    for(int i=0;i<2;i++)for(int j=n/2;j<n/2+n/4;j++){
        tmp[3-i][n+n/2-j-1]=tmp[i][j];
        tmp[i][j]=0;
    }
    insert_queue(0, 4, n/2+n/4, n);
    distribute_fish();
    flattening(0, 4, n/2+n/4, n);
}
int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++)cin>>ar[i];
    int cnt=0;
    while(!check()){
        cnt++;
        plus_fish();
        moving();
    }
    cout<<cnt;
    return 0;
}