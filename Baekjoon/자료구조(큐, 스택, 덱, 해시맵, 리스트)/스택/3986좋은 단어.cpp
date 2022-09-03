#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int main(){
    FastIO;
    int n, cnt=0;cin>>n;
    while(n--){
        string s, temp="";cin>>s;
        temp+=s.back();
        s.pop_back();
        while(!s.empty()){
            if(s.back()==temp.back()) temp.pop_back();
            else temp+=s.back();
            s.pop_back();
        }
        if(temp.empty())cnt++;
    }
    cout<<cnt;
    return 0;
}