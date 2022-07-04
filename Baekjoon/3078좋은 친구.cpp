#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int main(){
    FastIO;
    int n,k;cin>>n>>k;
    long long sum=0;
    queue<int> q[21];
    for(int i=0;i<n;i++){
        string s;cin>>s;
        while(!q[s.length()].empty() && q[s.length()].front()<i-k){
            q[s.length()].pop();
        }
        sum+=q[s.length()].size();
        q[s.length()].push(i);
    }
    cout<<sum;
    return 0;
}