#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int main() {
    FastIO;
    int n, L, P, i=0, cnt=0;cin>>n;
    vector<pair<int,int>> v;
    priority_queue<int,vector<int>,less<int>> pq;
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end());
    cin>>L>>P;
    while(P<L){
        while(i<n && v[i].first<=P){
            pq.push(v[i].second);
            i++;
        }
        if(pq.empty()){
            cout<<-1;
            return 0;
        }
        P+=pq.top();pq.pop();
        cnt++;
    }
    cout<<cnt;
}