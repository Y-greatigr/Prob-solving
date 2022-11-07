#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

long long dp[101][10][1<<10]={0,}; // 자릿수, 끝자리 수, 사용된 숫자 비트
int main(){
    FastIO;
    int N;cin>>N;
    for(int i=1;i<10;i++)dp[1][i][1<<i]=1;
    for(int i=2;i<=N;i++)for(int j=0;j<10;j++)for(int k=0;k<1024;k++){
        int bit=k|(1<<j);
        if(j>=1)dp[i][j][bit]=(dp[i][j][bit]+dp[i-1][j-1][k])%1'000'000'000;
        if(j<9)dp[i][j][bit]=(dp[i][j][bit]+dp[i-1][j+1][k])%1'000'000'000;
    }
    long long sum=0;
    for(int i=0;i<10;i++)sum=(sum+dp[N][i][1023])%1'000'000'000;
    cout<<sum;
    return 0;
}