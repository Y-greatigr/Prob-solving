#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int main(){
    FastIO;
    vector<char> c;
    map<char,int> m;
    int n;cin>>n;
    while(n--){
        string s;cin>>s;
        m[s[0]]++;
        if(m[s[0]]==5)c.push_back(s[0]);
    }
    sort(c.begin(),c.end());
    if(!c.empty())for(auto i:c)cout<<i;
    else cout<<"PREDAJA";
    return 0;
}