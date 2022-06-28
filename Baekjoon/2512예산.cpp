#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int main(){
    FastIO;
    int n, m, left=0, right=0, sum=0, ans=0;cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
        right=max(right,v[i]);
        sum+=v[i];
    }
    cin>>m;
    while(left<=right){
        int mid=(left+right)/2;
        int mid_sum=0;
        for(int i=0;i<n;i++){
            if(mid>=v[i])mid_sum+=v[i];
            else mid_sum+=mid;
        }
        if(mid_sum>m){
            right=mid-1;
        }
        else{
            if(mid_sum==sum){
                ans=mid;
                break;
            }
            ans=max(ans, mid);
            left=mid+1;
        }
    }
    cout<<ans;
    return 0;
}