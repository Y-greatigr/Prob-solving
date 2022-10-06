#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int ar[200'001];
void manacher(string s){
    int n=s.length();
    int r=0, p=0;
    for(int i=0;i<n;i++){
        if(r>=i)ar[i]=min(r-i, ar[2*p-i]);
        else ar[i]=0;
        while(i-ar[i]-1>=0 && i+ar[i]+1<n && s[i-ar[i]-1]==s[i+ar[i]+1])
            ar[i]++;
        if(r<i+ar[i]){
            r=i+ar[i];
            p=i;
        }
    }
}
int main(){
    FastIO;
    string s, temp="#";cin>>s;
    for(auto i:s){
        temp+=i;
        temp+='#';
    }
    manacher(temp);
    int maxi=0;
    for(int i=0;i<temp.length();i++){
        maxi=max(maxi,ar[i]);
    }
    cout<<maxi;
    return 0;
}