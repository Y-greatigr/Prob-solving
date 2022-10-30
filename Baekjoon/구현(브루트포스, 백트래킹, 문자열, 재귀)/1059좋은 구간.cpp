#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int main(){
    FastIO;
    int L, n;cin>>L;
    int ar[50];
    for(int i=0;i<L;i++)cin>>ar[i];
    sort(ar, ar+L);
    cin>>n;
    auto ind= lower_bound(ar, ar+L, n);
    if(*ind==n){
        cout<<0;
        return 0;
    }
    if(ind!=ar)cout<<(n-*(ind-1)) * (*ind-n) - 1;
    else cout<<(*ind-n)*n - 1;
    return 0;
}