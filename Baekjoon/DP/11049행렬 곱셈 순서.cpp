#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int ar[500][2];
int dp[500][500];
int main(){
    FastIO;
    int n;cin>>n;
    if(n==1){
        cout<<0;
        return 0;
    }
    for(int i=0;i<n;i++){
        cin>>ar[i][0]>>ar[i][1];
        fill(dp[i], dp[i]+n, INT_MAX);
    }
    for(int i=0;i<n-1;i++)dp[i][i+1]=ar[i][0]*ar[i][1]*ar[i+1][1];
    for(int j=2;j<n;j++){
        for(int i=j-2;i>=0;i--){
            for(int k=i;k<j;k++){
                if(i==k)dp[i][j]=min(dp[i][j], dp[k+1][j]+ar[i][0]*ar[i][1]*ar[j][1]);
                else if(k+1==j)dp[i][j]=min(dp[i][j], dp[i][k]+ar[i][0]*ar[k][1]*ar[j][1]);
                else dp[i][j]=min(dp[i][j], dp[i][k]+dp[k+1][j]+ ar[i][0]*ar[k][1]*ar[j][1]);
            }
        }
    }
    cout<<dp[0][n-1];
    return 0;
}