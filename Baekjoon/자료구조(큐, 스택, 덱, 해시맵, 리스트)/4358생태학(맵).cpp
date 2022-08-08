#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int main(){
    FastIO;
    map<string,double> m;
    string s;
    int cnt=0;
    while(getline(cin, s)){
        m[s]++, cnt++;
    }
    cout<<fixed;
    cout.precision(4);
    for(auto i:m){
        cout<<i.first<<" "<<(i.second/cnt)*100<<'\n';
    }
    return 0;
}