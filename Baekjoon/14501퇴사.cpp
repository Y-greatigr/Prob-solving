#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int main(){
    FastIO;
    int a[2][16], dp[16], maxi=0;
    int n;cin>>n;
    for(int i=1;i<=n;i++){cin>>a[0][i]>>a[1][i];dp[i]=a[1][i];}
    for(int i=1;i<=n;i++){
        if(a[0][i]+i>n+1)continue;
        for(int j=1;j<i;j++){
            if(i-j>=a[0][j])dp[i]=max(dp[i],dp[j]+a[1][i]);
        }
        maxi=max(dp[i], maxi);
    }
    cout<<maxi;
    return 0;
}
