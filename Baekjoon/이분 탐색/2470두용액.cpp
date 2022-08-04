#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int main(){
    FastIO;
    int n;cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        v.emplace_back(a);
    }
    sort(v.begin(), v.end());
    int left=0, right=v.size()-1, mid, pre=2'000'000'000, ans_left=v[left], ans_right=v[right];
    while(left<right){
        if(v[left]+v[right]==0){ans_left=v[left],ans_right=v[right];break;}
        mid=abs(v[left]+v[right]);
        if(mid<pre)ans_left=v[left],ans_right=v[right], pre=mid;
        if(abs(v[left])>abs(v[right]))left+=1;
        else right-=1;
    }
    cout<<ans_left<<" "<<ans_right;
    return 0;
}