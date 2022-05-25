#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int main(){
    FastIO;
    int n;cin>>n;
    priority_queue<int,vector<int>, greater<>> min_heap;
    priority_queue<int,vector<int>, less<>> max_heap;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        if(min_heap.size()<max_heap.size())min_heap.push(a);
        else max_heap.push(a);
        if(!min_heap.empty() && !max_heap.empty() && min_heap.top()<max_heap.top()){
            int less=min_heap.top(), greater=max_heap.top();
            min_heap.pop();max_heap.pop();
            min_heap.push(greater);max_heap.push(less);
        }
        cout<<max_heap.top()<<'\n';
    }
    return 0;
}