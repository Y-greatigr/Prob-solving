#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int a[50][50];
int b[50][50]={0,};

int main(){
    FastIO;
    queue<pair<int,int>> q;
    int R,C,T, x1, x2, sum=0;cin>>R>>C>>T;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>a[i][j];
            if(a[i][j]==-1)x1=i-1,x2=i;
        }
    }
    while(T--){
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(a[i][j]<=0)continue;
                int cnt=0;
                for(int p=0;p<4;p++){
                    int x=i+"1012"[p]-'1';
                    int y=j+"2101"[p]-'1';
                    if(x<0 || x>=R || y<0 || y>=C || (x==x1 && y==0) || (x==x2 && y==0))continue;
                    cnt++;
                    b[x][y]+=(a[i][j]/5);
                }
                a[i][j]-=((a[i][j]/5)*cnt);
            }
        }

        // 가운데 공간들
        for(int i=1;i<x1;i++)for(int j=1;j<C-1;j++) {a[i][j]+=b[i][j];b[i][j]=0;}
        for(int i=x2+1;i<R-1;i++)for(int j=1;j<C-1;j++) {a[i][j]+=b[i][j];b[i][j]=0;}
        
        /**
         * @brief 공기청정기 상단 반시계
         * 
         */
        int tmp1=a[x1][C-1]+b[x1][C-1];b[x1][C-1]=0;
        for(int j=C-1;j>1;j--){a[x1][j]=a[x1][j-1]+b[x1][j-1];b[x1][j-1]=0;}
        a[x1][1]=0;
        
        int tmp2=a[0][C-1]+b[0][C-1];b[0][C-1]=0;
        for(int x=0;x<x1-1;x++){a[x][C-1]=a[x+1][C-1]+b[x+1][C-1];b[x+1][C-1]=0;}
        a[x1-1][C-1]=tmp1;
        
        int tmp3=a[0][0]+b[0][0];b[0][0]=0;
        for(int j=0;j<C-1;j++){a[0][j]=a[0][j+1]+b[0][j+1];b[0][j+1]=0;}
        a[0][C-2]=tmp2;

        for(int i=x1-1;i>0;i--){a[i][0]=a[i-1][0]+b[i-1][0];b[i-1][0]=0;}
        a[1][0]=tmp3;
        b[x1-1][0]=0;

        /**
         * @brief 공기청정기 하단 시계
         * 
         */
        tmp1=a[x2][C-1]+b[x2][C-1];b[x2][C-1]=0;
        for(int j=C-1;j>1;j--){a[x2][j]=a[x2][j-1]+b[x2][j-1];b[x2][j-1]=0;}
        a[x2][1]=0;
        
        tmp2=a[R-1][C-1]+b[R-1][C-1];b[R-1][C-1]=0;
        for(int x=R-1;x>x2;x--){a[x][C-1]=a[x-1][C-1]+b[x-1][C-1];b[x-1][C-1]=0;}
        a[x2+1][C-1]=tmp1;
        
        tmp3=a[R-1][0]+b[R-1][0];b[R-1][0]=0;
        for(int j=0;j<C-1;j++){a[R-1][j]=a[R-1][j+1]+b[R-1][j+1];b[R-1][j+1]=0;}
        a[R-1][C-2]=tmp2;

        for(int i=x2+1;i<R-1;i++){a[i][0]=a[i+1][0]+b[i+1][0];b[i+1][0]=0;}
        a[R-2][0]=tmp3;
        b[x2+1][0]=0;
    }

    for(int i=0;i<R;i++)for(int j=0;j<C;j++)sum+=a[i][j];
    cout<<sum+2;
    return 0;
}