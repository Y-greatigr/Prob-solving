#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int ar[100'001];
int main(){
    FastIO;
    int n,k;cin>>n>>k;
    int left=1, right=2'000'000, maxi=0;
    for(int i=1;i<=n;i++)cin>>ar[i];
    while(left<right){
        int mid=(left+right)/2;
        int cnt=0, sum=0;
        for(int i=1;i<=n;i++){
            sum+=ar[i];
            if(sum>=mid){
                cnt++;
                sum=0;
            }
        }
        if(cnt<k){
            right=mid;
        }
        else{
            left=mid+1;
            maxi=(maxi,mid);
        }
    }
    cout<<maxi;
    return 0;
}