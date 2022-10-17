#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

long long CCW(pair<long long, long long> a, pair<long long, long long> b, pair<long long, long long> c){
    return (b.first-a.first)*(c.second-a.second)-(c.first-a.first)*(b.second-a.second);
}
int check2(pair<long long, long long> a, pair<long long, long long> b, pair<long long, long long> c){
    if(CCW(a,b,c)<0)return -1;
    else if(CCW(a,b,c)==0)return 0;
    else return 1;
}
bool check(pair<long long, long long> a, pair<long long, long long> b, pair<long long, long long> c, pair<long long, long long> d){
    return check2(a,b,c)*check2(a,b,d)<0 && check2(c,d, a)*check2(c,d,b)<0;
}
int main(){
    FastIO;
    pair<long long, long long> a,b,c,d;
    cin>>a.first>>a.second>>b.first>>b.second>>c.first>>c.second>>d.first>>d.second;
    if(check(a,b,c,d))cout<<1;
    else cout<<0;
    return 0;
}