#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int main(){
    FastIO;
    int k,m;cin>>k>>m;
    list<int> li;
    for(int i=1;i<=k;i++)li.push_back(i);
    while(m--){
        auto it=li.begin();
        int r, i=1;cin>>r;
        while(it!=li.end()){
            if(i%r==0){
                it=li.erase(it++);
            }
            else it++;
            i++;
        }
    }
    for(auto i:li){
        cout<<i<<'\n';
    }
    return 0;
}