#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

long long ar[1'001][1'001]={0,};
int main(){
    FastIO;
    int t;cin>>t;
    ar[1][1]=1;
    ar[2][1]=1,ar[2][2]=1;
    ar[3][1]=1,ar[3][2]=2,ar[3][3]=1;
    for(int i=4;i<=1'000;i++){
        for(int j=2;j<=i;j++){
            ar[i][j]=(ar[i-1][j-1]+ar[i-2][j-1]+ar[i-3][j-1])%1'000'000'009;
        }
    }
    for(int i=1;i<=1'000;i++){
        for(int j=2;j<=i;j++){
            ar[i][j]=(ar[i][j]+ar[i][j-1])%1'000'000'009;
        }
    }
    while(t--){
        int n,m;cin>>n>>m;
        cout<<ar[n][m]<<'\n';
    }
    return 0;
}