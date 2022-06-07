#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int ar[26][200'001]={0,};
int main(){
    FastIO;
    string s;
    int q;
    cin>>s>>q;
    ar[s[0]-'a'][0]=1;
    for(int i=1;i<s.length();i++){
        for(int j=0;j<26;j++){
            ar[j][i]=ar[j][i-1];
        }
        ar[s[i]-'a'][i]=ar[s[i]-'a'][i-1]+1;
    }
    while(q--){
        char c;
        int a,b;
        cin>>c>>a>>b;
        cout<<ar[c-'a'][b]-ar[c-'a'][a-1]<<'\n';
    }
    return 0;
}