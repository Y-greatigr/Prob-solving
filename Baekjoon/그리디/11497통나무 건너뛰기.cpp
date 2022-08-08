#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int main(){
    FastIO;
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++)cin>>v[i];
        sort(v.begin(),v.end());
        int maxi=0;
        for(int i=2;i<n;i++){
            maxi=max(maxi,max(abs(v[i]-v[i-1]), abs(v[i]-v[i-2])));
        }
        cout<<maxi<<'\n';
    }
    return 0;
}