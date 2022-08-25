#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

bool dp[2501][2501]={false,};
int dp2[2501]={0,};
int main(){
    FastIO;
    string a;cin>>a;
    a="."+a;
    for(int i=1;i<a.length();i++)dp[i][1]=1;
    for(int j=2;j<a.length();j++){
        for(int i=1;i<a.length();i++){
            if(i+j-1>a.length() || a[i]!=a[i+j-1] || (j>2 && !dp[i+1][j-2])) dp[i][j]=false;
            else dp[i][j]=true;
        }
    }
    for(int i=1;i<a.length();i++){
        if(dp[1][i])dp2[i]=1;
        else{
            dp2[i]=dp2[i-1]+1;
            for(int j=2;j<i;j++){
                if(dp[j][i-j+1]) dp2[i]=min(dp2[i],dp2[j-1]+1);
            }
        }
    }
    cout<<dp2[a.length()-1];
    return 0;
}