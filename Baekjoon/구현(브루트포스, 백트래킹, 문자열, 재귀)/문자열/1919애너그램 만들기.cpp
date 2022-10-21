#include<bits/stdc++.h>

using namespace std;

int main(){
    string a,b;cin>>a>>b;
    int ar[26]={0,};
    int cnt=0;
    for(int i=0;i<a.length();i++)ar[a[i]-'a']++;
    for(int i=0;i<b.length();i++)ar[b[i]-'a']--;
    for(int i=0;i<26;i++)cnt+=abs(ar[i]);
    cout<<cnt;
    return 0;
}