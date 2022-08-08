#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int main(){
    FastIO;
    int n, a=2;cin>>n;
    if(n==1)return 0;
    while(a<=n){
        if(!(n%a)){
            cout<<a<<'\n';
            n/=a;
        }
        else a++;
    }
    return 0;
}