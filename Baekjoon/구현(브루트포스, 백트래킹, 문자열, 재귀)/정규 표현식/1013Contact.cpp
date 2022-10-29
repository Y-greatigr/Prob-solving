#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int main(){
    FastIO;
    int n;cin>>n;
    regex re("(100+1+|01)+",  regex::icase);
    while(n--){
        string s;cin>>s;
        if(regex_match(s,re))cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}