#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int main(){
    FastIO;
    int ar[50][50];
    int n,m, maxi=1;cin>>n>>m;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++){
        char c;cin>>c;
        ar[i][j]=c-'0';
    }
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)for(int k=1;k<max(n,m);k++){
        if(i+k<n && j+k<m && ar[i][j]==ar[i][j+k]
        && ar[i][j+k]==ar[i+k][j+k] && ar[i+k][j+k]==ar[i+k][j]){
            maxi=max(maxi,(int)pow(k+1,2));
        }
    }
    cout<<maxi;
    return 0;
}