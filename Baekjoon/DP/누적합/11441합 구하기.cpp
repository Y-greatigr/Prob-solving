#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int dp[100'001]={0,};
int main(){
    FastIO;
    int n,m;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>dp[i];
        dp[i]+=dp[i-1];
    }
    cin>>m;
    while(m--){
        int a,b;cin>>a>>b;
        cout<<dp[b]-dp[a-1]<<'\n';
    }
    return 0;
}