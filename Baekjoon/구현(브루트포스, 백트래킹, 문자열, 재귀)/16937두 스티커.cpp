#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

vector<pair<int,int>> v;
bool can_stick(pair<int,int> a, pair<int,int> b, int h, int w){
    if(a.first<=h && b.first<=h && a.second<=w && b.second<=w && (h-a.first>=b.first || w-a.second>=b.second)) return true;
    if(a.first<=w && b.first<=w && a.second<=h && b.second<=h && (w-a.first>=b.first || h-a.second>=b.second)) return true;
    if(a.first<=h && b.second<=h && a.second<=w && b.first<=w && (h-a.first>=b.second || w-a.second>=b.first)) return true;
    if(a.first<=w && b.second<=w && a.second<=h && b.first<=h && (w-a.first>=b.second || h-a.second>=b.first)) return true;
    return false;
}
int main(){
    FastIO;
    int h,w,n, maxi=0;cin>>h>>w>>n;
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        v.push_back({a,b});
    }
    for(int i=0;i<v.size()-1;i++){
        for(int j=i+1;j<v.size();j++){
            if(can_stick(v[i],v[j], h, w))
                maxi=max(v[i].first*v[i].second+v[j].first*v[j].second,maxi);
        }
    }
    cout<<maxi;
    return 0;
}