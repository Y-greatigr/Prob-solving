#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int main(){
    FastIO;
    int n;cin>>n;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++)cin>>v[i];
    deque<int> dq;
    for(int i=1;i<=n;i++)dq.push_back(i);
    while(!dq.empty()){
        cout<<dq.front()<<" ";
        int cnt=v[dq.front()];dq.pop_front();
        if(dq.empty())break;
        if(cnt>0){
            for(int i=0;i<cnt-1;i++){
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        else{
            for(int i=0;i<abs(cnt);i++){
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }
    return 0;
}