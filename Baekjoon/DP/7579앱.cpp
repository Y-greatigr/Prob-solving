#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int ar[101][2];
int dp[10'001]={0,};    // 비활성화 비용 i일 때, 최대 메모리 확보량
int main(){
    FastIO;
    int n,m, sum=0;cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>ar[i][0];
    for(int i=1;i<=n;i++){
        cin>>ar[i][1];
        sum+=ar[i][1];
    }
    for(int i=1;i<=n;i++){
        for(int j=sum;j>=ar[i][1];j--){ //15 0
            dp[j]=max(dp[j],dp[j-ar[i][1]]+ar[i][0]);
        }
    }
    for(int i=0;i<=sum;i++){
        if(dp[i]>=m){
            cout<<i;
            return 0;
        }
    }
    return 0;
}