#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int ar[100'000];
int main(){
    FastIO;
    int n, sum=0;cin>>n;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        auto cur= lower_bound(ar, ar+sum, a);
        *cur=a;
        if(ar+sum==cur)sum++;
    }
    cout<<n-sum;
    return 0;
}