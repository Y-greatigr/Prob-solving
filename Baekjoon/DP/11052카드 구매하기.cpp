#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int main(){
    FastIO;
    int n;cin>>n;
    int ar[1001]={0,}, dp[1001]={0,};
    for(int i=1;i<=n;i++)cin>>ar[i];
    for(int i=1;i<=n;i++){
        dp[i]=ar[i];
        for(int j=1;j<=i;j++){
            dp[i]=max(dp[i],dp[j]+dp[i-j]);
        }
    }
    cout<<dp[n];
    return 0;
}