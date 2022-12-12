#include <bits/stdc++.h>
#define FastIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;

int main(){
    FastIO;
    long long a, b, gap=6;cin>>a>>b;
    long long ans=b*(6*b-4)/2+1;
    if(a)gap*=b;
    for(int i=0;i<a;i++){
        ans+=gap;
        gap+=6;
    }
    cout<<ans;
    return 0;
}