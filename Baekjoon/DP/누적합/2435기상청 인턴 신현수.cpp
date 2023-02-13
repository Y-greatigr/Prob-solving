#include <bits/stdc++.h>
#define FastIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;

int main(){
    FastIO;
    int ar[100], maxi=-10000, sum=0;
    int N,K;cin>>N>>K;
    for(int i=0;i<N;i++){
        cin>>ar[i];
        sum+=ar[i];
        if(i-K>=-1){
            if(i-K>=0)sum-=ar[i-K];
            maxi=max(maxi,sum);
        }
    }
    cout<<maxi;
    return 0;
}