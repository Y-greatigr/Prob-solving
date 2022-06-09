#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int main(){
    FastIO;
    int t;cin>>t;
    while(t--){
        int k;cin>>k;
        long long sum=0;
        priority_queue<long long,vector<long long>, greater<long long>> pq;
        while(k--){
            int a;cin>>a;
            pq.push(a);
        }
        while(pq.size()>1){
            long long a = pq.top();pq.pop();
            a += pq.top();pq.pop();
            sum+=a;
            pq.push(a);
        }
        cout<<sum<<'\n';
    }
    return 0;
}