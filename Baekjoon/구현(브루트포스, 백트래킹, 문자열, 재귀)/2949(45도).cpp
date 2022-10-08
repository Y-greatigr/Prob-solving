#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

char ar[10][10], tmp[10][10];
int main(){
    FastIO;
    int r,c;cin>>r>>c;
    for(int i=0;i<r;i++)for(int j=0;j<c;j++)cin>>ar[i][j];

    int k;cin>>k;
    k%=360; // k가 360이면 0도와 마찬가지이므로

    // 초기 180, 225, 270, 315 해당
    // 180도 회전
    if(k>=180){
        k-=180;
        for(int i=0;i<r;i++)for(int j=0;j<c;j++)tmp[i][j]=ar[i][j];
        for(int i=0;i<r;i++)for(int j=0;j<c;j++)ar[i][j]=tmp[r-i-1][c-j-1];
    }

    // 초기 135, 90, 270, 315 해당
    // 시계방향으로 90도 회전
    if(k>=90){
        k-=90;
        for(int i=0;i<r;i++)for(int j=0;j<c;j++)tmp[i][j]=ar[i][j];
        for(int i=0;i<r;i++)for(int j=0;j<c;j++)ar[j][r-i-1]=tmp[i][j];
        swap(r,c);
    }

    // 이미 위에서 돌릴만큼 돌렸거나 아예 0이거나
    if(k==0){
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++)cout<<ar[i][j];
            cout<<'\n';
        }
        return 0;
    }

    // 최종 45도로 남게된 아이들
    for(int i=0;i<r+c-1;i++){
        int x,y;
        if(i<r){
            for(int j=0;j<r-i-1;j++)cout<<" ";
            x=i,y=0;
        }
        else {
            for(int j=0;j<i-r+1;j++)cout<<" ";
            x=r-1,y=i-r+1;
        }
        cout<<ar[x][y];
        while(x-1>=0 && y+1<c){
            x--, y++;
            cout<<" "<<ar[x][y];
        }
        if(i!=r+c-2)cout<<'\n';
    }
    return 0;
}