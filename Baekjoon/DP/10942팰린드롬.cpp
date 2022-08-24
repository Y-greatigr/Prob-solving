#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int ar[2001];
int dp[2001][2001]={0,};
int main(){
    FastIO;
    int n,m;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>ar[i];
        dp[i][1]=1;
    }
    for(int j=2;j<=n;j++)for(int i=1;i<=n;i++){
        if(i+j-1>n || ar[i]!=ar[i+j-1]
        || (j>2 && !dp[i+1][j-2])) dp[i][j]=0;
        else dp[i][j]=1;
    }
    cin>>m;
    while(m--){
        int st,en;cin>>st>>en;
        cout<<dp[st][en-st+1]<<'\n';
    }
    return 0;
}