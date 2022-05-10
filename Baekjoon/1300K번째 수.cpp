#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int main(){
    FastIO;
    long long n, k;cin>>n>>k;
    long long left=1, right=n*n, answer=n*n;
    while(left<=right){
        long long mid=(left+right)/2;
        long long cnt=0;
        for(int i=1;i<=n;i++){
            if(i>mid)break;
            cnt+=min(mid,n*i)/i;
        }
        if(cnt>=k){
            answer=mid;
            right=mid-1;
        }
        else left=mid+1;
    }
    cout<<answer;
    return 0;
}