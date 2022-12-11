#include <bits/stdc++.h>
#define FastIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;

int main(){
    FastIO;
    long long s,k, mul=1;cin>>s>>k;
    for(long long i=0; i<k-s%k;i++)mul*=s/k;
    for(long long i=0; i<s%k;i++)mul*=(s/k+1);
    cout<<mul;
    return 0;
}