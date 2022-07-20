#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

long long ar[100'001][2];
int main(){
    FastIO;
    int t;cin>>t;
    ar[1][0]=1,ar[1][1]=0;
    ar[2][0]=1,ar[2][1]=1;
    ar[3][0]=2,ar[3][1]=2;
    for(int i=4;i<=100'000;i++){
        ar[i][0]=(ar[i-1][1]+ar[i-2][1]+ar[i-3][1])%1'000'000'009;
        ar[i][1]=(ar[i-1][0]+ar[i-2][0]+ar[i-3][0])%1'000'000'009;
    }
    while(t--){
        int n;cin>>n;
        cout<<ar[n][0]<<" "<<ar[n][1]<<'\n';
    }
    return 0;
}