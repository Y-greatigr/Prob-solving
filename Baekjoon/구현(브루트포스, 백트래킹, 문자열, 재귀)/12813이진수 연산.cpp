#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int main(){
    FastIO;
    bitset<100'000> bit1, bit2;cin>>bit1>>bit2;
    cout<<(bit1&bit2)<<'\n';
    cout<<(bit1|bit2)<<'\n';
    cout<<(bit1^bit2)<<'\n';
    cout<<bit1.flip()<<'\n';
    cout<<bit2.flip()<<'\n';
    return 0;
}