#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int a[1'000'000];
int main(){
    FastIO;
    int n, sum=0;cin>>n;
    for(int i=0;i<n;i++){
        int b;cin>>b;
        auto cur= lower_bound(a, a+sum, b);
        *cur=b;
        if(cur==a+sum)sum++;
    }
    cout<<sum;
    return 0;
}