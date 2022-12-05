#include <bits/stdc++.h>
#define FastIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;

int main(){
    FastIO;
    long long n;cin>>n;
    vector<long long> v(6);
    for(int i=0;i<6;i++)cin>>v[i];
    if(n==1)cout<<accumulate(v.begin(),v.end(),0) - max({v[0],v[1],v[2],v[3],v[4],v[5]});
    else {
        cout<<((n-2)*(n-2)*5+(n-2)*4)*min({v[0],v[1],v[2],v[3],v[4],v[5]})
        + min({v[0]+v[1]+v[2], v[0]+v[1]+v[3], v[0]+v[3]+v[4]
        , v[0]+v[2]+v[4], v[1]+v[3]+v[5], v[5]+v[1]+v[2]
        , v[3]+v[4]+v[5], v[2]+v[4]+v[5]})*4
        + min({v[0]+v[1], v[0]+v[2], v[0]+v[3], v[0]+v[4],
        v[5]+v[1], v[5]+v[2], v[5]+v[3], v[5]+v[4],
        v[4]+v[3], v[4]+v[2], v[1]+v[3], v[1]+v[2]})*((n-2)*4+(n-1)*4);
    }
    return 0;
}