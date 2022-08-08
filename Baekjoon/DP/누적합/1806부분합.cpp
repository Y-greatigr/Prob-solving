#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int main(){
    FastIO;
    int n,s, mini=INT_MAX, sum=0, left=0;cin>>n>>s;
    int *ar=new int[n];
    for(int i=0;i<n;i++){
        cin>>ar[i];
        sum+=ar[i];
        if(sum>=s){
            while(sum-ar[left]>=s)sum-=ar[left++];
            mini=min(mini,i-left+1);
        }
    }
    cout<<(mini==INT_MAX?0:mini);
    return 0;
}