#include <bits/stdc++.h>
#define FastIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;

int main(){
    FastIO;
    char ar[100][10];
    string a,b;cin>>a>>b;
    for(int i=0;i<a.length();i++)for(int j=i*b.length()/a.length(), cnt=0;cnt<b.length()/a.length();j++,cnt++){
        ar[cnt][i]=b[j];
    }
    vector<pair<char,int>> v;
    for(int i=0;i<a.length();i++){
        v.emplace_back(a[i],i);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<b.length()/a.length();i++){
        int cnt=0;
        while(cnt<a.length()){
            for(int j=0;j<a.length();j++){
                if(v[j].second==cnt)cout<<ar[i][j];
            }
            cnt++;
        }
    }
    return 0;
}