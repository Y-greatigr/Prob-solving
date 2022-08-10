#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

long long recur(long long k){
    if(k==1)return 0;
    long long i=1;
    while(i<k){
        i*=2;
    }
    i/=2;
    return !recur(k-i);
}
int main(){
    FastIO;
    long long k;cin>>k;
    cout<<recur(k);
    return 0;
}