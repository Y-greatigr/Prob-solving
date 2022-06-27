#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

string to_binary(string s){
    int k = stoi(s);
    string num="";
    while(k>0){
        num=to_string(k%2)+num;
        k/=2;
    }
    while(num.length()<8){
        num="0"+num;
    }
    return num;
}
string to_decimal(string s){
    string k = s.substr(0,8);
    string num="";
    int a=0;
    for(int i=0;i<8;i++){
        if(k[i]=='0')continue;
        a+=pow(2,(7-i));
    }
    num+= to_string(a)+".";

    a=0;
    k=s.substr(8,8);
    for(int i=0;i<8;i++){
        if(k[i]=='0')continue;
        a+=pow(2,(7-i));
    }
    num+= to_string(a)+".";

    a=0;
    k=s.substr(8,8);k=s.substr(16,8);
    for(int i=0;i<8;i++){
        if(k[i]=='0')continue;
        a+=pow(2,(7-i));
    }
    num+= to_string(a)+".";

    a=0;
    k=s.substr(8,8);k=s.substr(24);
    for(int i=0;i<8;i++){
        if(k[i]=='0')continue;
        a+=pow(2,(7-i));
    }
    num+= to_string(a);

    return num;
}
int main(){
    FastIO;
    int n;cin>>n;
    vector<string> v;
    for(int i=0;i<n;i++){
        string s;cin>>s;

        int ind=s.find(".");
        string vi=to_binary(s.substr(0,ind));

        s=s.substr(ind+1);
        ind=s.find(".");
        vi+= to_binary(s.substr(0,ind));

        s=s.substr(ind+1);
        ind=s.find(".");
        vi+= to_binary(s.substr(0,ind));

        s=s.substr(ind+1);
        vi+= to_binary(s);

        v.emplace_back(vi);
    }
    int j;
    for(j=0;j<32;j++){
        bool flag=true;
        for(int i=1;i<n;i++){
            if(v[i][j]!=v[i-1][j]){
                flag=false;
                break;
            }
        }
        if(!flag)break;
    }
    string address="", mask="";
    for(int i=0;i<32;i++){
        if(i<j){
            address+=v[0][i];
            mask+="1";
        }
        else{
            address+="0";
            mask+="0";
        }
    }
    cout<<to_decimal(address)<<'\n'<<to_decimal(mask);
    return 0;
}