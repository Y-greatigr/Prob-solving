#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int main(){
    FastIO;
    vector<int> v;
    long long n, sum=0;cin>>n;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        v.emplace_back(a);
    }
    sort(v.begin(),v.end());
    for(int i=1;i<=n;i++){
        sum+=abs(i-v[i-1]);
    }
    cout<<sum;
    return 0;
}