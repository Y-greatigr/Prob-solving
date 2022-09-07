#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

bool a[50][50], b[50][50];
int main(){
    FastIO;
    int n,m, cnt=0;cin>>n>>m;
    for(int i=0;i<2*n;i++){
        string s;cin>>s;
        for(int j=0;j<m;j++){
            if(i<n)a[i][j]=(s[j]-'0'?true:false);
            else b[i-n][j]=(s[j]-'0'?true:false);
        }
    }
    for(int i=0;i<n-2;i++)for(int j=0;j<m-2;j++){
        if(!(a[i][j]^b[i][j]))continue;
        for(int k=i;k<i+3;k++)for(int p=j;p<j+3;p++) a[k][p]=!a[k][p];
        cnt++;
    }
    for(int i=0;i<n;i++)for(int j=0;j<m;j++){
        if((a[i][j]^b[i][j])){
            cout<<-1;
            return 0;
        }
    }
    cout<<cnt;
    return 0;
}