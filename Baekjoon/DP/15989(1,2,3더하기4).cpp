#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int ar[10'001][3];
int main(){
    FastIO;
    int t;cin>>t;
    ar[1][0]=1, ar[1][1]=0, ar[1][2]=0;
    ar[2][0]=1, ar[2][1]=1, ar[2][2]=0;
    ar[3][0]=1, ar[3][1]=1, ar[3][2]=1;
    for(int i=4;i<10'001;i++){
        ar[i][0]=ar[i-1][0];    // 1로 끝나는 것들
        ar[i][1]=ar[i-2][0]+ar[i-2][1]; // 2로 끝나는 것들
        ar[i][2]=ar[i-3][0]+ar[i-3][1]+ar[i-3][2];  // 3으로 끝나는 것들
    }
    while(t--){
        int n;cin>>n;
        cout<<ar[n][0]+ar[n][1]+ar[n][2]<<'\n';
    }
    return 0;
}