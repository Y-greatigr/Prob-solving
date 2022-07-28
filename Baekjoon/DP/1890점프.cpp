#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

long long dp[100][100]={0,};
int main(){
    FastIO;
    int n;cin>>n;
    dp[0][0]=1;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++){
        int a;cin>>a;
        if(!a)continue;
        if(i+a<n)dp[i+a][j]+=dp[i][j];
        if(j+a<n)dp[i][j+a]+=dp[i][j];
    }
    cout<<dp[n-1][n-1];
    return 0;
}