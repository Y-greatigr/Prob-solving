#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int a[1'000'000];
int main(){
    FastIO;
    int n, sum=1;cin>>n;
    cin>>a[0];
    for(int i=1;i<n;i++){
        int b;cin>>b;
        int left=0, right=sum, mid;
        while(left<right){
            mid=(left+right)/2;
            if(a[mid]<b) left=mid+1;
            else right=mid;
        }
        if(right==sum)sum++;
        a[right]=b;
    }
    cout<<sum;
    return 0;
}