#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

typedef vector<vector<long long>> matrix;
#define MOD 1'000'000'007

matrix mul(matrix a, matrix b){
    return {{((a[0][0]*b[0][0])%MOD+(a[0][1]*b[1][0])%MOD)%MOD,
             ((a[0][0]*b[0][1])%MOD+(a[0][1]*b[1][1])%MOD)%MOD},
            {((a[1][0]*b[0][0])%MOD+(a[1][1]*b[1][0])%MOD)%MOD,
             ((a[1][0]*b[0][1])%MOD+(a[1][1]*b[1][1])%MOD)%MOD}};
}
long long fib(long long n){
    matrix ans={{1,0},{0,1}};
    matrix a={{1,1},{1,0}};
    while(n>0){
        if(n%2)ans=mul(ans, a);
        a=mul(a,a);
        n/=2;
    }
    return ans[0][1]%MOD;
}
int main(){
    FastIO;
    long long n;cin>>n;
    if(n<2)cout<<n;
    else cout<<fib(n);
    return 0;
}