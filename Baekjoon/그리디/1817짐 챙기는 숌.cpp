#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int main(){
    FastIO;
    int n,m;cin>>n>>m;
    int tmp=m, cnt=n?1:0;
    for(int i=0;i<n;i++){
        int t;cin>>t;
        tmp-=t;
        if(tmp<0)cnt++,tmp=m-t;
    }
    cout<<cnt;
    return 0;
}