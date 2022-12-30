#include <bits/stdc++.h>
#define FastIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;

int main(){
    FastIO;
    int ar[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    string ans[7]={"MON", "TUE","WED","THU","FRI","SAT","SUN"};
    int a,b;cin>>a>>b;
    int cnt = b-1;
    for(int i=1;i<a;i++)cnt+=ar[i];
    cnt%=7;
    cout<<ans[cnt];
    return 0;
}