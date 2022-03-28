#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int main(){
    FastIO;
    int n,k, w, v;cin>>n>>k;
    int dp[k+1]={};
    for(int i=1;i<=n;i++){
        cin>>w>>v;
        for(int j=k;j>=w;j--){
            if(dp[j-w]+v>dp[j])
                dp[j]=dp[j-w]+v;
        }
    }
    cout<<dp[k];
    return 0;
}