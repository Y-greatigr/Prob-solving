#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int dice[6]={0,};
void rotate(int k){
    if(k==1){
        int tmp=dice[0];
        dice[0]=dice[3];
        dice[3]=dice[5];
        dice[5]=dice[1];
        dice[1]=tmp;
    }
    else if(k==2){
        int tmp=dice[0];
        dice[0]=dice[1];
        dice[1]=dice[5];
        dice[5]=dice[3];
        dice[3]=tmp;
    }
    else if(k==3){
        int tmp=dice[0];
        dice[0]=dice[4];
        dice[4]=dice[5];
        dice[5]=dice[2];
        dice[2]=tmp;
    }
    else if(k==4){
        int tmp=dice[0];
        dice[0]=dice[2];
        dice[2]=dice[5];
        dice[5]=dice[4];
        dice[4]=tmp;
    }
}
int main(){
    FastIO;
    int N,M,x,y,K;cin>>N>>M>>x>>y>>K;
    int a[N][M];
    for(int i=0;i<N;i++)for(int j=0;j<M;j++)cin>>a[i][j];
    while(K--){
        int k;cin>>k;
        int nx=x+"01102"[k]-'1';
        int ny=y+"02011"[k]-'1';
        if(nx>=N || nx<0 || ny>=M || ny<0)continue;
        x=nx,y=ny;
        rotate(k);
        if(!a[x][y])a[x][y]=dice[5];
        else {dice[5]=a[x][y];a[x][y]=0;}
        if(!K){
            cout<<dice[0];
            return 0;
        }
        cout<<dice[0]<<'\n';
    }
    return 0;
}
