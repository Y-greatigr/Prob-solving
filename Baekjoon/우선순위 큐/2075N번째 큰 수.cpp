#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int main(){
    FastIO;
    int n;cin>>n;
    priority_queue<int,vector<int>, greater<>> pq;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++){
        int a;cin>>a;
        if(pq.size()<n)pq.push(a);
        else if(pq.top()<a)pq.pop(),pq.push(a);
    }
    cout<<pq.top();
    return 0;
}