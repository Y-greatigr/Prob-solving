#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

long long ar[1'000'001]={0, };
int main(){
    FastIO;
    ar[1]=1,ar[2]=2;
    int n;cin>>n;
    for(int i=3;i<=n;i++){
        ar[i]=(ar[i-2]+ar[i-1])%15746;
    }
    cout<<ar[n];
    return 0;
}