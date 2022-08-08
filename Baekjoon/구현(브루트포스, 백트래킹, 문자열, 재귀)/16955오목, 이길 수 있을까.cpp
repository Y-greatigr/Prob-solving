#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

char ar[10][10];

bool check2(int k, int x, int y, int flag){
    for(int i=x+k, j=y+k, t=y-k;i<x+k+5 && j<y+k+5 && t>=y-k-4;i++,j++,t--){
        if(flag==1 && (j<0 || j>=10 || ar[x][j]=='O' || ar[x][j]=='.'))return false;
        if(flag==2 && (j<0 || j>=10 || ar[j][x]=='O' || ar[j][x]=='.'))return false;
        if(flag==3 && (j<0 || i<0 || j>=10 || i>=10 || ar[i][j]=='O' || ar[i][j]=='.'))return false;
        if(flag==4 && (t<0 || i<0 || t>=10 || i>=10 || ar[i][t]=='O' || ar[i][t]=='.'))return false;
    }
    return true;
}
bool check(int x, int y){
    for(int k=-4;k<1;k++){
        if(check2(k, x, y, 1))return true;
        if(check2(k, y, x, 2))return true;
        if(check2(k, x, y, 3))return true;
        if(check2(k, x, y, 4))return true;
    }
    return false;
}
int main(){
    FastIO;
    for(int i=0;i<10;i++)for(int j=0;j<10;j++)cin>>ar[i][j];
    for(int i=0;i<10;i++)for(int j=0;j<10;j++){
        if(ar[i][j]=='X' || ar[i][j]=='O')continue;
        ar[i][j]='X';
        if(check(i,j)){
            cout<<1;
            return 0;
        }
        ar[i][j]='.';
    }
    cout<<0;
    return 0;
}