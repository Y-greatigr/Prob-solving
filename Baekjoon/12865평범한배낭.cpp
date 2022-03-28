#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

/**
 * @brief 특정 무게별 제일 가치 있는 배낭들
 * 
 */
int a[101][2]; // {무게, 가치}
int dp[101][100'001];
int main(){
    FastIO;
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i][0]>>a[i][1];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            if(j>=a[i][0]) dp[i][j]=max(dp[i-1][j], dp[i-1][j-a[i][0]]+a[i][1]);
            else dp[i][j]=dp[i-1][j];
        }
    }
    cout<<dp[n][k];
    return 0;
}
