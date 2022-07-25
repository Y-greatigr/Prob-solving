#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int main(){
    FastIO;
    int n, m, left=0, right=0, cnt=0, sum=0;cin>>n>>m;
    vector<int> v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    while(left<n && right<n){
        sum+=v[right];
        if(sum>m){
            sum-=v[left++];
            sum-=v[right];
        }
        else if(sum==m){
            cnt++;
            sum-=v[left++];
            right++;
        }
        else{
            right++;
        }
    }
    cout<<cnt;
    return 0;
}