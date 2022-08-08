#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int main(){
    FastIO;
    vector<pair<int,int>> v;
    int n, maxi=1;cin>>n;
    int dp[100]={0,};
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(), v.end());
    for(int i=0;i<n;i++){
        dp[i]=1;
        for(int j=0;j<i;j++){
            if(v[j].second<v[i].second){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        maxi=max(maxi, dp[i]);
    }
    cout<<n-maxi;
    return 0;
}