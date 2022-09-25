#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

bool overall_flag=true;
string not_k(string k){
    for(int i=0;i<k.length();i++){
        if(k[i]=='0')k[i]='1';
        else k[i]='0';
    }
    return k;
}
string plus_one_k(string k){
    bool flag=true;
    overall_flag=true;
    for(int i=k.length()-1;i>=0;i--){
        if(k[i]=='1' && flag)k[i]='0';
        else if(k[i]=='0' && flag)k[i]='1',flag=false, overall_flag=false;
    }
    return k;
}
string and_k(string k, string s){
    for(int i=0;i<s.length();i++){
        if(k[i]=='1' && s[i]=='1')s[i]='1';
        else s[i]='0';
    }
    return s;
}
string minus_k(string k, string s){
    bool flag=false;
    for(int i=k.length()-1;i>=0;i--) {
        if(k[i]=='1' && s[i]=='1' && !flag)s[i]='0',flag=true;
        else if(k[i]=='1' && s[i]=='1' && flag)s[i]='1';
        else if(k[i]!=s[i] && flag)s[i]='0';
        else if(k[i]!=s[i] && !flag)s[i]='1';
        else if(k[i]=='0' && s[i]=='0' && !flag)s[i]='0';
        else if(k[i]=='0' && s[i]=='0' && flag)s[i]='1',flag= false;
    }
    return plus_one_k(s);
}
int main(){
    FastIO;
    int n, cnt=0;
    string k;cin>>n>>k;
    while(true){
        k = minus_k(k,not_k(and_k(k,plus_one_k(not_k(k)))));
        cnt++;
        if(overall_flag)break;
    }
    cout<<cnt;
    return 0;
}