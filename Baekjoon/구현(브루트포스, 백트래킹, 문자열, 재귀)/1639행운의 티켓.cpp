#include <bits/stdc++.h>
#define FastIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;

int main(){
    FastIO;
    string s;cin>>s;
    int a=0, b=1, maxi=0;
    while(b<s.length()){
        int c=a++,d=b++, sum_a=0, sum_b=0;
        while(c>=0 && d<s.length()){
            sum_a+=s[c]-'0';
            sum_b+=s[d]-'0';
            if(sum_a==sum_b)maxi=max(maxi,d-c+1);
            c--,d++;
        }
    }
    cout<<maxi;
    return 0;
}