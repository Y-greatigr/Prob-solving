#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int main(){
    FastIO;
    vector<int> v;
    int n,c, ans=1;cin>>n>>c;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    int left=1, right=v[v.size()-1]-v[0];
    while(left<=right){
        int mid=(left+right)/2, cnt=1, st=v[0];
        for(int i=0;i<n;i++){
            if(mid<=v[i]-st)cnt++,st=v[i];
            if(cnt==c)break;
        }
        if(cnt>=c) ans=mid, left=mid+1;
        else right=mid-1;
    }
    cout<<ans;
    return 0;
}