#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int main(){
    FastIO;
    string a,b;cin>>a>>b;
    int mini=INT_MAX;
    for(int i=0;i<=b.length()-a.length();i++){
        int sum=0;
        for(int j=0;j<a.length();j++){
            if(a[j]!=b[j+i])sum++;
        }
        mini=min(mini, sum);
    }
    cout<<mini;
    return 0;
}