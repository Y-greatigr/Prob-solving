#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int main(){
    FastIO;
    int n;cin>>n;
    int ar[51];
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].first;
        v[i].second=i;
    }
    sort(v.begin(), v.end());
    for(int i=0;i<n;i++){
        ar[v[i].second]=i;
    }
    for(int i=0;i<n;i++){
        cout<<ar[i]<<" ";
    }
    return 0;
}