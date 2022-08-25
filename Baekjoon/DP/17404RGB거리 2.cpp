#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int ar[1000][3];
int dp[1000][3]={0,};
int main(){
    FastIO;
    int n, mini=100'000'000;cin>>n;
    for(int i=0;i<n;i++)cin>>ar[i][0]>>ar[i][1]>>ar[i][2];
    for(int j=0;j<3;j++) {
        for(int i=0;i<3;i++){
            if(i==j)dp[0][i]=ar[0][i];
            else dp[0][i]=100'000'000;
        }
        for (int i = 1; i < n ; i++) {
            dp[i][0]=dp[i][1]=dp[i][2]=0;
            dp[i][0] += min(dp[i - 1][1], dp[i - 1][2]) + ar[i][0];
            dp[i][1] += min(dp[i - 1][0], dp[i - 1][2]) + ar[i][1];
            dp[i][2] += min(dp[i - 1][1], dp[i - 1][0]) + ar[i][2];
        }
        for(int i=0;i<3;i++){
            if(i==j)continue;
            mini = min(mini, dp[n-1][i]);
        }
    }
    cout<<mini;
    return 0;
}