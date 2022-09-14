#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

bool check(string s){
    if(s[0]=='_')return true;
    if(s.back()=='_')return true;
    if(s[0]>='A' && s[0]<='Z')return true;
    for(int i=0;i<s.length()-1;i++){
        if(s[i]=='_' && s[i+1]=='_')return true;
    }
    return false;
}
bool check_2(string s){
    for(int i=0;i<s.length();i++){
        if(s[i]>='A' && s[i]<='Z'){
            cout<<"Error!";
            return true;
        }
    }
    return false;
}
void cpp_to_java(string s){
    string ans="";
    for(int i=0;i<s.length();i++){
        if(s[i]=='_'){
            ans+=(char)(s[(i++)+1]-32);;
            continue;
        }
        ans+=s[i];
    }
    cout<<ans;
}
void java_to_cpp(string s){
    string ans="";
    for(int i=0;i<s.length();i++){
        if(s[i]>='A' && s[i]<='Z'){
            ans+="_";
            ans+=(char)(s[i]+32);
            continue;
        }
        ans+=s[i];
    }
    cout<<ans;
}
int main(){
    FastIO;
    string s;cin>>s;
    if(check(s)){
        cout<<"Error!";
        return 0;
    }
    if(s.find("_")!=string::npos){
        if(check_2(s))return 0;
        cpp_to_java(s);
    }
    else java_to_cpp(s);
    return 0;
}