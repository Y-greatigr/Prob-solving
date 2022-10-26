#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int ar[1'000'000], tmp[1'000'000], pos[1'000'000];
int main(){
    FastIO;
    int n, sum=0;cin>>n;
    for(int i=0;i<n;i++){
        cin>>tmp[i];
        auto cur= lower_bound(ar, ar+sum, tmp[i]);
        *cur=tmp[i];
        pos[i]=cur-ar;
        if(cur==ar+sum){
            sum++;
        }
    }
    cout<<sum<<'\n';
    vector<int> v;
    for(int i=n-1, cnt=sum-1;i>=0;i--){
        if(pos[i]==cnt){
            v.push_back(tmp[i]);
            cnt--;
        }
    }
    reverse(v.begin(), v.end());
    for(auto i:v)cout<<i<<" ";
    return 0;
}