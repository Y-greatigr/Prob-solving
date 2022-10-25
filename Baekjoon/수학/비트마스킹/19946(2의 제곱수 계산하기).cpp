#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int main(){
    FastIO;
    unsigned long long n, k=1;cin>>n;
    for(int i=1;i<65;i++){
        k<<=1;
        unsigned long long tmp=k-1;
        for(int j=1;j<65;j++){
            if(tmp==n){
                cout<<i;
                return 0;
            }
            tmp<<=1;
        }
    }
    return 0;
}