#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int main(){
    FastIO;
    int n,k;cin>>n>>k;
    vector<int> ar(n);
    for(int i=0;i<n;i++)cin>>ar[i];
    int dp[10001]={0,};
    fill(dp+1, dp+10001, 10001);
    for(int i=0;i<n;i++)for(int j=ar[i];j<=k;j++){
        dp[j]=min(dp[j],dp[j-ar[i]]+1);
    }
    if (dp[k]>10000)cout<<-1;
    else cout<<dp[k];
    return 0;
}