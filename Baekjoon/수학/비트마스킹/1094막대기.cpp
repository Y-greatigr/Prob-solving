#include <bits/stdc++.h>
#define FastIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;

int main(){
    FastIO;
    int k;cin>>k;
    int ar[65];
    for(int i=1;i<=64;i++){
        ar[i]=INT_MAX;
        bool flag=false;
        for(int j=1;j<=64;j*=2){
            if(i==j){
                flag=true,ar[i]=1;
                break;
            }
        }
        if(flag)continue;
        for(int j=1;j<i;j++){
            ar[i]=min(ar[i],ar[j]+ar[i-j]);
        }
    }
    cout<<ar[k];
    return 0;
}