#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int main(){
    FastIO;
    map<char,double> m;
    int n;
    string s;
    cin>>n>>s;
    vector<double> v;
    for(int i=0;i<n;i++){
        double a;cin>>a;
        m[(char)('A'+i)]=a;
    }
    for(int i=0;i<s.length();i++){
        if(s[i]>='A' && s[i]<='Z')v.push_back(m[s[i]]);
        else {
            double b=v.back();v.pop_back();
            double a=v.back();v.pop_back();
            if(s[i]=='*')v.push_back(a*b);
            else if(s[i]=='+')v.push_back(a+b);
            else if(s[i]=='/')v.push_back(a/b);
            else if(s[i]=='-')v.push_back(a-b);
        }
    }
    cout<<fixed;
    cout.precision(2);
    cout<<v.back();
    return 0;
}