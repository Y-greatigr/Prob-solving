#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int main(){
    FastIO;
    map<string,int> m;
    string s;cin>>s;
    for(int i=0;i<s.length();i++){
        for(int j=1;j<=s.length()-i;j++){
            m[s.substr(i, j)]=1;
        }
    }
    cout<<m.size();
    return 0;
}