#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int main(){
    FastIO;
    int n;cin>>n;
    vector<int> v;
    deque<int> d;
    for(int i=1;i<=n;i++){
        int a;cin>>a;
        v.push_back(a);
    }
    for(int i=1;i<=n;i++){
        int a=v[n-i];
        if(a==1)d.push_front(i);
        if(a==2)d.insert(d.begin()+1, i);
        if(a==3)d.push_back(i);
    }
    for(int i=0;i<n;i++)cout<<d[i]<<" ";
    return 0;
}