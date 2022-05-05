#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int main() {
    FastIO;
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<pair<int,int>> v;
    int n, sum = 0;cin >> n;
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(), v.end());
    pq.push(v[0].second);
    for(int i=1;i<n;i++) {
        while (!pq.empty()) {
            if(pq.top()<=v[i].first)pq.pop();
            else break;
        }
        pq.push(v[i].second);
        sum=max(sum, (int)pq.size());
    }
    cout<<sum;
    return 0;
}