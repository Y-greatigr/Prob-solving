#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int main(){
    FastIO;
    int n,m;cin>>n>>m;
    unordered_set<string> keywords;
    for(int i=0;i<n;i++){
        string s;cin>>s;
        keywords.insert(s);
    }
    while(m--){
        string s;cin>>s;
        int ind=s.find(",");
        while(ind!=string::npos){
            string sub=s.substr(0,ind);
            keywords.erase(sub);
            s=s.substr(ind+1);
            ind=s.find(",");
        }
        keywords.erase(s);
        cout<<keywords.size()<<'\n';
    }
    return 0;
}