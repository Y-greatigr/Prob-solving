#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int ar[1001][1001];
int main(){
    FastIO;
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++){
        ar[i][0]=1;
        ar[i][i]=1;
        for(int j=1;j<i;j++){
            ar[i][j]=(ar[i-1][j-1]+ar[i-1][j]) % 10'007;
        }
    }
    cout<<ar[n][k];
    return 0;
}