#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int main(){
    FastIO;
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    sort(v.rbegin(),v.rend());
    int maxi=0;
    for(int i=1;i<=n;i++){
        maxi=max(maxi,v[i-1]*i);
    }
    cout<<maxi;
    return 0;
}