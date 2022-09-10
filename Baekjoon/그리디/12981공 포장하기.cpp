#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int main(){
    FastIO;
    vector<int> v(3);
    cin>>v[0]>>v[1]>>v[2];
    sort(v.begin(),v.end());
    int cnt=v[0];
    v[1]-=v[0], v[2]-=v[0];

    if(v[1]%3==1 && v[2]%3==1){
        cnt+=v[1]/3+v[2]/3;
        cout<<cnt+1;
        return 0;
    }

    if(v[1]%3)cnt+=v[1]/3+1;
    else cnt+=v[1]/3;
    if(v[2]%3)cnt+=v[2]/3+1;
    else cnt+=v[2]/3;

    cout<<cnt;
    return 0;
}