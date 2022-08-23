#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int dp[1001][1001]={0,};
int main(){
    FastIO;
    string a,b;cin>>a>>b;
    for(int i=1;i<=b.length();i++){
        for(int j=1;j<=a.length();j++){
            if(b[i-1]==a[j-1]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        }
    }
    int k=a.length();
    string ans="";
    for(int i=b.length();i>0;i--){
        for(int j=k;j>0;j--){
            if(!dp[i][k] || dp[i][j]==dp[i-1][j])break;
            if(dp[i][j]!=dp[i][j-1]){
                ans=a[j-1]+ans;
                k=j-1;
                break;
            }
        }
    }
    cout<<dp[b.length()][a.length()]<<'\n';
    cout<<ans;
    return 0;
}