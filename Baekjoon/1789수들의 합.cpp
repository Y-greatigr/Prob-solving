#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int main(){
    FastIO;
    long long s, ans=1, sum=0, cnt=0;cin>>s;
    while(sum<s){
        sum+=ans;
        ans++;
        if(sum<=s)cnt++;
    }
    cout<<cnt;
    return 0;
}