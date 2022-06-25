#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int main(){
    FastIO;
    int n,m,k;cin>>n>>m;
    int ar[300][300]={0,};
    for(int i=0;i<n;i++){
        cin>>ar[i][0];
        for(int j=1;j<m;j++){
            int a;cin>>a;
            ar[i][j]=ar[i][j-1]+a;
        }
    }
    cin>>k;
    while(k--){
        int i,j,x,y;cin>>i>>j>>x>>y;
        int sum=0;
        for(int p=i-1;p<x;p++){
            if(j==1)sum+=ar[p][y-1];
            else sum+=(ar[p][y-1]-ar[p][j-2]);
        }
        cout<<sum<<'\n';
    }
    return 0;
}