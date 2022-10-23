#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int main(){
    FastIO;
    long long n, mini=1'000'000'000'000;cin>>n;
    long long left=0, right=sqrt(pow(2,63)-1)+1;
    while(left<right){
        long long mid=(left+right)/2;
        if(mid*mid>=n){
            mini=min(mini,mid);
            right=mid;
        }
        else{
            left=mid+1;
        }
    }
    if(mini==1'000'000'000'000)cout<<right;
    else cout<<mini;
    return 0;
}