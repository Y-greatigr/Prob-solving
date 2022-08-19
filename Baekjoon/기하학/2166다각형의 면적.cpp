#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

long double ar[2][10000];
int main(){
    FastIO;
    int n;cin>>n;
    long double plus=0, minus=0;
    cin>>ar[0][0]>>ar[1][0];
    for(int i=1;i<n;i++){
        cin>>ar[0][i]>>ar[1][i];
        plus+=ar[0][i-1]*ar[1][i];
        minus+=ar[1][i-1]*ar[0][i];
    }
    plus+=ar[0][n-1]*ar[1][0];
    minus+=ar[1][n-1]*ar[0][0];

    cout<<fixed;
    cout.precision(1);
    cout<<abs(plus-minus)/2;
    return 0;
}