#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int a[16][16];
int dp[16][16][3];
int main(){
    FastIO;
    int N;cin>>N;
    for(int i=0;i<N;i++)for(int j=0;j<N;j++){cin>>a[i][j];dp[i][j][0]=0;dp[i][j][1]=0;dp[i][j][2]=0;}
    dp[0][1][0]=1;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(a[i][j])continue;
            if(j>0 && !(i==0 && j==1)) dp[i][j][0]=dp[i][j-1][0]+dp[i][j-1][1];    // 가로
            if(i>0 && j>0 && !a[i-1][j] && !a[i][j-1]) dp[i][j][1]=dp[i-1][j-1][0]+dp[i-1][j-1][1]+dp[i-1][j-1][2]; //대각선
            if(i>0)dp[i][j][2]=dp[i-1][j][2]+dp[i-1][j][1]; // 세로
        }
    }
    cout<<dp[N-1][N-1][0]+dp[N-1][N-1][1]+dp[N-1][N-1][2];
    return 0;
}
