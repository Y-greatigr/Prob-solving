#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int main(){
    FastIO;
    int ar[1000]={0,}, dp[1000]={0,};
    int n, maxi=1;cin>>n;
    for(int i=0;i<n;i++){
        cin>>ar[i];
        for(int j=0;j<i;j++){
            if(ar[i]<ar[j]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        if(!dp[i])dp[i]=1;
        maxi=max(dp[i],maxi);
    }
    cout<<maxi;
    return 0;
}