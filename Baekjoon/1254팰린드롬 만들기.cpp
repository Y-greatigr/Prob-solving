#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int main(){
    FastIO;
    string s;cin>>s;
    for(int i=0;i<s.length();i++){
        string a=s.substr(i);
        string b=a;
        reverse(b.begin(),b.end());
        if(a==b){
            cout<<s.length()+i;
            break;
        }
    }
    return 0;
}