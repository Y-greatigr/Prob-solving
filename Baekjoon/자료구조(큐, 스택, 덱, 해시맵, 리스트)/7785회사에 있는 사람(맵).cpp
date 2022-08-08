#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int main(){
    FastIO;
    map<string, bool, greater<string>> m;
    int n;cin>>n;
    while(n--){
        string a,b;cin>>a>>b;
        if(b=="enter")m[a]=true;
        if(b=="leave")m.erase(a);
    }
    for(auto i : m)
        cout<<i.first<<'\n';
    return 0;
}