#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int main(){
    FastIO;
    int k, n=1, cnt=0, cnt2=0;cin>>k;
    while(k>n){
        n*=2;
        cnt++;
    }
    if(pow(2,cnt)==k){
        cout<<n<<" "<<0;
        return 0;
    }
    while(k){
        cnt--;
        cnt2++;
        if(k-pow(2,cnt)>=0)k-=pow(2,cnt);
    }
    cout<<n<<" "<<cnt2;
    return 0;
}