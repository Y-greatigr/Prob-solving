#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
long long ar[100'001];
int main(){
    FastIO;
    int t;cin>>t;
    ar[1]=1, ar[2]=2, ar[3]=2, ar[4]=3, ar[5]=3, ar[6]=6;
    for(int i=7;i<=100'000;i++){
        ar[i]=(ar[i-2]+ar[i-4]+ar[i-6])%1'000'000'009;
    }
    while(t--){
        int n;cin>>n;
        cout<<ar[n]<<'\n';
    }
    return 0;
}