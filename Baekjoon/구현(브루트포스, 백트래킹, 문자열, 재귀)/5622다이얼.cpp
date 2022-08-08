#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int main(){
    FastIO;
    map<char,int> m;
    int j=3, cnt=0, sum=0;
    for(int i=65;i<90;i++){
        if(i==83)continue;
        m[(char)(0+i)]=j;cnt++;
        if(cnt==3)j++,cnt=0;
    }
    m['S']=8;
    m['Z']=10;
    string s;cin>>s;
    for(int i=0;i<s.length();i++) sum+=m[s[i]];
    cout<<sum;
    return 0;
}