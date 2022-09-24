#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int main(){
    FastIO;
    int n, c=1;cin>>n;
    map<int,int> m;
    for(int i=1;i<32;i++){
        m[c]=1;
        c*=2;
    }
    if(m.find(n)!=m.end())cout<<1;
    else cout<<0;
    return 0;
}