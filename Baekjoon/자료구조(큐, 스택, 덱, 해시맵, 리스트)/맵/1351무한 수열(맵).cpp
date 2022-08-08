#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

map<long long, long long> m;
long long rec(long long n, long long p, long long q){
    if(m.find(n)!=m.end())return m[n];
    return m[n]=rec(n/p, p, q)+rec(n/q,p,q);
}
int main(){
    FastIO;
    long long N,P,Q;
    cin>>N>>P>>Q;
    m[0]=1;
    cout<<rec(N, P, Q);
    return 0;
}