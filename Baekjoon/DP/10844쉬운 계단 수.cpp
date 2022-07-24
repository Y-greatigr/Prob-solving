#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int main(){
    FastIO;
    int n;cin>>n;
    long long ar[101][10]={0, };
    for(int i=1;i<10;i++)ar[1][i]=1;
    for(int i=2;i<=n;i++)for(int j=0;j<10;j++){
        if(j==0)ar[i][j]=ar[i-1][1];
        else if(j==9)ar[i][j]=ar[i-1][8];
        else ar[i][j]=(ar[i-1][j-1]+ar[i-1][j+1])%1'000'000'000;
    }
    long long ans=0;
    for(int i=0;i<10;i++)ans+=ar[n][i];
    cout<<ans%1'000'000'000;
    return 0;
}