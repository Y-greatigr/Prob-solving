#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int main(){
    FastIO;
    int n;
    string k;cin>>n>>k;
    cout<<count(k.begin(), k.end(),'1');
    return 0;
}