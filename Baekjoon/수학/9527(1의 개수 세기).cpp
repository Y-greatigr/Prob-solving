#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

long long cal(long long k){
    long long answer=0;
    for(int i=0;i<55;i++)answer+=((k+1)/(1ll<<i+1))*(1ll<<i)+max(0ll,(k+1)%(1ll<<i+1)-(1ll<<i));
    return answer;
}
int main(){
    FastIO;
    long long a,b;cin>>a>>b;
    cout<<cal(b)-cal(a-1);
    return 0;
}