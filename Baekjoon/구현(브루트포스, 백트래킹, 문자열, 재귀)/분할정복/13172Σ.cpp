#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
#define MOD 1'000'000'007
using namespace std;

int main(){
    FastIO;
    int m;cin>>m;
    long long real_ans=0;
    while(m--){
        long long n,s;cin>>n>>s;
        long long ans=1, mod=MOD-2;
        while(mod>0){
            if(mod%2)ans=(ans*n)%MOD;
            n=(n*n)%MOD;
            mod/=2;
        }
        ans=(ans*s)%MOD;
        real_ans=(real_ans+ans)%MOD;
    }
    cout<<real_ans;
    return 0;
}