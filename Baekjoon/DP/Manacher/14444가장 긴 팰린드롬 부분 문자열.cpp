#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int ar[200'001];
string extension_s(string s){
    string k="#";
    for(char i : s){
        k+=i;
        k+="#";
    }
    return k;
}
int main(){
    FastIO;
    string s;cin>>s;
    s=extension_s(s);
    int r=0,p=0, maxi=0;
    for(int i=0;i<s.length();i++){
        if(r>=i)ar[i]=min(r-i,ar[2*p-i]);
        else ar[i]=0;
        while(i-ar[i]-1>=0 && i+ar[i]+1<s.length() && s[i-ar[i]-1]== s[i+ar[i]+1]){
            ar[i]++;
        }
        if(r<i+ar[i]){
            r=i+ar[i];
            p=i;
        }
    }
    for(int i=0;i<s.length();i++)maxi=max(maxi,ar[i]);
    cout<<maxi;
    return 0;
}