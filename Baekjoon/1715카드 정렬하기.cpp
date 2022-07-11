#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int main(){
    FastIO;
    int n;cin>>n;
    long long sum=0;
    priority_queue<long long, vector<long long>, greater<>> pq;
    while(n--){
        int a;cin>>a;
        pq.push(a);
    }
    while(pq.size()>1){
        long long a=pq.top();pq.pop();
        a+=pq.top();pq.pop();
        sum+=a;
        pq.push(a);
    }
    cout<<sum;
    return 0;
}