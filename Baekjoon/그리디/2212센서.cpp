#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int main(){
    FastIO;
    int n,k, sum=0;cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    sort(v.begin(),v.end());
    vector<int> dif(n-1);
    for(int i=0;i<n-1;i++)dif[i]=v[i+1]-v[i];
    sort(dif.begin(),dif.end());
    for(int i=0;i<n-k;i++)sum+=dif[i];
    cout<<sum;
    return 0;
}