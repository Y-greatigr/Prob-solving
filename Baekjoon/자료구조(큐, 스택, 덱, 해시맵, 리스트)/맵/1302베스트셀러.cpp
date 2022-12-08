#include <bits/stdc++.h>
#define FastIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;

int main(){
    FastIO;
    int n, cnt=0;cin>>n;
    string ans="...";
    map<string,int> m;
    while(n--){
        string a;cin>>a;
        m[a]++;
        if(m[a]>cnt){
            cnt=m[a];
            ans=a;
        }
        else if(m[a]==cnt && a<ans)ans=a;
    }
    cout<<ans;
    return 0;
}