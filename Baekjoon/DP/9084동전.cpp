#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int main(){
    FastIO;
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int ar[20];
        for(int i=0;i<n;i++)cin>>ar[i];
        int m;cin>>m;
        int dp[10'001]={0,};
        dp[0]=1;
        for(int i=0;i<n;i++)for(int j=ar[i];j<=m;j++){
            dp[j]+=dp[j-ar[i]];
        }
        cout<<dp[m]<<'\n';
    }
    return 0;
}