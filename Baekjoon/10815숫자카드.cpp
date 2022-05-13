#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int main(){
    FastIO;
    int n,m;cin>>n;
    vector<int> v;
    while(n--){
        int k;cin>>k;
        v.push_back(k);
    }
    sort(v.begin(), v.end());
    cin>>m;
    while(m--){
        int k;cin>>k;
        int left=0, right=v.size()-1, mid;
        while(left<=right){
            mid=(left+right)/2;
            if(v[mid]<k) left=mid+1;
            else if(v[mid]>k)right=mid-1;
            else break;
        }
        if(v[mid]==k)cout<<"1 ";
        else cout<<"0 ";
    }
    return 0;
}