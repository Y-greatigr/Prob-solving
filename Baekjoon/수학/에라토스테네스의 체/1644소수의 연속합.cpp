#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

bool ar[4'000'001]={false,};
int prime[4'000'001]={0,};
int main(){
    FastIO;
    int n, ind=1, cnt=0;cin>>n;
    ar[1]=true;
    for(int i=2;i*i<=n;i++) {
        if (!ar[i]) {
            for (int j = i*i; j <= n; j+=i) ar[j] = true;
        }
    }
    for(int i=1;i<=n;i++){
        if(!ar[i]){
            if(!prime[ind])prime[ind]=i;
            else prime[ind+1]=prime[ind]+i, ind++;
        }
    }
    int left=ind-1, right=ind;
    while(left>=0){
        if(prime[right]-prime[left]>n)right--;
        else if(prime[right]-prime[left]<n)left--;
        else cnt++, left--, right--;
    }
    cout<<cnt;
    return 0;
}