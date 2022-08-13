#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int ar[100'000];
int main(){
    FastIO;
    int n;
    while(cin>>n){
        memset(ar,0,sizeof(ar));
        int sum=0;
        for(int i=0;i<n;i++){
            int b;cin>>b;
            auto cur= lower_bound(ar, ar+sum, b);
            *cur=b;
            if(cur==ar+sum)sum++;
        }
        cout<<sum<<'\n';
    }
    return 0;
}