#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int main(){
    FastIO;
    int n;cin>>n;
    int left=1, right=1, cnt=0, sum=1;
    while(left<=right && right<=n){
        if(sum<n)sum+=++right;
        else if(sum>n)sum-=left++;
        else{
            cnt++;
            sum-=left++;
        }
    }
    cout<<cnt;
    return 0;
}