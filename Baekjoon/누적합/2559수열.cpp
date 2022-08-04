#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int ar[100001];
int main(){
    FastIO;
    int n,k;cin>>n>>k>>ar[0];
    int sum=ar[0];
    for(int i=1;i<k;i++) {
        cin>>ar[i];
        sum+=ar[i];
    }
    int maxi=sum;
    for(int i=k;i<n;i++){
        cin>>ar[i];
        sum+=ar[i]-ar[i-k];
        maxi=max(maxi, sum);
    }
    cout<<maxi;
    return 0;
}