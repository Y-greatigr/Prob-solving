#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int main(){
    FastIO;
    int n, sum=0;cin>>n;
    vector<int> a(n), b(n);
    for(int i=0;i<2*n;i++){
        if(i<n)cin>>a[i];
        else cin>>b[i-n];
    }
    sort(a.begin(),a.end());
    sort(b.rbegin(),b.rend());
    for(int i=0;i<n;i++)sum+=a[i]*b[i];
    cout<<sum;
    return 0;
}