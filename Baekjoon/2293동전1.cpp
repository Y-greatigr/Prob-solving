#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int main(){
    FastIO;
    int n,k;cin>>n>>k;
    vector<int> ar(n);
    for(int i=0;i<n;i++)cin>>ar[i];
    sort(ar.begin(), ar.end());
    int dp[10001]={0,};
    dp[0]=1;
    for(int i=0;i<n;i++)for(int j=ar[i];j<=k;j++){
        dp[j]+=dp[j-ar[i]];
    }
    cout<<dp[k];
    return 0;
}