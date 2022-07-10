#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int main(){
    FastIO;
    int t;cin>>t;
    while(t--){
        string s;cin>>s;
        list<char> v;
        auto it=v.begin();
        for(int i=0;i<s.length();i++){
            if(s[i]=='<'){
                if(it!=v.begin())it--;
            }
            else if(s[i]=='>'){
                if(it!=v.end())it++;
            }
            else if(s[i]=='-'){
                if(it!=v.begin()){
                    it=v.erase(--it);
                }
            }
            else{
                v.insert(it, s[i]);
            }
        }
        cout<<string(v.begin(),v.end());
        cout<<'\n';
    }
    return 0;
}