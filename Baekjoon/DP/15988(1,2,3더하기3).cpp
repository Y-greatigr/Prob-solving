#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
long long ar[1'000'001]={0,};

int main(){
    FastIO;
    int t;cin>>t;
    ar[1]=1, ar[2]=2, ar[3]=4;
    for(int i=4;i<=1'000'000;i++)
        ar[i] = ( ar[i-1] + ar[i-2] + ar[i-3] ) % 1'000'000'009;
    while(t--){
        int n;cin>>n;
        cout<<ar[n]<<'\n';
    }
    return 0;
}