#include <bits/stdc++.h>

using namespace std;

int main(){
    string ar[10]={"black", "brown", "red", "orange", "yellow",
                   "green", "blue", "violet", "grey", "white"};
    map<string,pair<long long,long long>> m;
    for(long long i=0;i<10;i++){
        m[ar[i]]={i,pow(10,i)};
        }
        string a,b,c;cin>>a>>b>>c;
        cout << m[a].first*m[c].second*10+m[b].first*m[c].second;

        return 0;
    }