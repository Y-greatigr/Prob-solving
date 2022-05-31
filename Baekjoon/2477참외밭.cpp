#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int main(){
    FastIO;
    int n, maxi=0, sub=0;cin>>n;
    int ar[6];
    for(int i=0;i<6;i++){
        int a;cin>>a>>ar[i];
    }
    for(int i=0;i<6;i++){
        if(ar[i]*ar[(i+1)%6]>maxi){
            maxi=ar[i]*ar[(i+1)%6];
            sub=ar[(i+3)%6]*ar[(i+4)%6];
        }
    }
    cout<<(maxi-sub)*n;
    return 0;
}