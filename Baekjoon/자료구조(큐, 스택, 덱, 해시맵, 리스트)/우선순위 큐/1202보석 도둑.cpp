#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int main(){
    FastIO;
    long long n,k, sum=0;cin>>n>>k;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> jewel;
    priority_queue<int,vector<int>, less<>> pq;
    vector<int> bag;
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        jewel.push({a,b});
    }
    for(int i=0;i<k;i++){
        int a;cin>>a;
        bag.push_back(a);
    }
    sort(bag.begin(),bag.end());
    for(int i=0;i<k;i++){
        while(!jewel.empty() && jewel.top().first<=bag[i]){
            pq.push(jewel.top().second);
            jewel.pop();
        }
        if(!pq.empty()){
            sum+=pq.top();
            pq.pop();
        }
    }
    cout<<sum;
    return 0;
}