#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int main(){
    FastIO;
    int t;cin>>t;
    for(int i=1;i<=t;i++){
        string s;cin>>s;
        int k=s.length()-1;
        int a=stoi(s.substr(0, 3));
        int first=a/100, second=a/10%10, third=a%10;
        if(third>=5){
            second++;
            if(second==10){
                first++;
                second=0;
                if(first==10){
                    cout<<'#'<<i<<" 1.0*10^"<<k+1<<'\n';
                    continue;
                }
            }
        }
        cout<<'#'<<i<<" "<<first<<"."<<second<<"*10^"<<k<<'\n';
    }
    return 0;
}