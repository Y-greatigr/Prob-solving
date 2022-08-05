#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

priority_queue<long long,vector<long long>, greater<long long>> pq;
set<long long> s;
int main(){
    FastIO;
    long long ar[100];
    long long k,n, maxi=0;cin>>k>>n;
    for(int i=0;i<k;i++)cin>>ar[i];
    pq.push(1);
    while(n--){
        long long cur=pq.top();pq.pop();
        for(int i=0;i<k;i++){
            long long x=cur*ar[i];
            if(s.find(x)!=s.end())continue;
            if(pq.size()<=n){
                pq.push(x);
                maxi=max(maxi,x);
                s.insert(x);
            }
            else if(maxi>x){
                pq.push(x);
                s.insert(x);
            }
        }
    }
    cout<<pq.top();
    return 0;
}