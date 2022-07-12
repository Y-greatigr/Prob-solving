#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int main(){
    FastIO;
    int n,m, sum=0;cin>>n>>m;
    map<pair<int,int>,int> ma;
    while(m--){
        int a,b;cin>>a>>b;
        if(a<b)ma[{a,b}]=1;
        else ma[{b,a}]=1;
    }
    for(int i=1;i<=n-2;i++)for(int j=i+1;j<=n-1;j++)for(int k=j+1;k<=n;k++){
        if(ma.find({i,j})!=ma.end() || ma.find({j,k})!=ma.end()
        || ma.find({i,k})!=ma.end())continue;
        sum++;
    }
    cout<<sum;
    return 0;
}