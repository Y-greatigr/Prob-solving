#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int main(){
    FastIO;
    vector<int> s;
    map<char,int> m;
    for(int i=0;i<26;i++)m[(char)('A'+i)]=0;
    int n, sum=0;cin>>n;
    for(int i=0;i<n;i++){
        string a;cin>>a;
        reverse(a.begin(),a.end());
        for(int j=0, k=1; j<a.length();j++){
            m[a[j]]+=k;
            k*=10;
        }
    }
    for(int i=0;i<26;i++){
        if(m[(char)('A'+i)]==0)continue;
        s.emplace_back(m[(char)('A'+i)]);
    }
    sort(s.begin(),s.end());
    for(int i=0, j=10-s.size();i<s.size();i++,j++)
        sum+=s[i]*j;
    cout<<sum;
    return 0;
}