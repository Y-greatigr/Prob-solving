#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int main(){
    FastIO;
    int a[1000], dp[1000]={0,}, n, maxi;cin>>n>>a[0];
    maxi=dp[0]=a[0];
    for(int i=1;i<n;i++){
        cin>>a[i];
        dp[i]=a[i];
        for(int j=0;j<i;j++){
            if(a[i]>a[j] && dp[j]+a[i]>dp[i])dp[i]=dp[j]+a[i];
        }
        maxi=max(maxi,dp[i]);
    }
    cout<<maxi;
    return 0;
}