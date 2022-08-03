#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

bool cmp(int a, int b){
    return a>b;
}
int main(){
    FastIO;
    int n, sum=0;cin>>n;
    vector<int> minus, plus;
    bool flag=false;
    while(n--){
        int a;cin>>a;
        if(!a)flag=true;
        else if(a>0)plus.emplace_back(a);
        else minus.emplace_back(a);
    }
    sort(minus.begin(),minus.end());
    sort(plus.begin(), plus.end(), cmp);
    for(int i=1;i<minus.size();i+=2)sum+=(minus[i-1]*minus[i]);
    for(int i=1;i<plus.size();i+=2)sum+=max(plus[i-1]+plus[i], plus[i-1]*plus[i]);
    if(!flag && minus.size()%2)sum+=minus.back();
    if(plus.size()%2)sum+=plus.back();
    cout<<sum;
    return 0;
}