#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int main(){
    FastIO;
    int n;
    long long sum=0, ans=0;cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
        sum+=v[i];
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        sum-=v[i];
        ans+=(v[i]*sum);
    }
    cout<<ans;
    return 0;
}