#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int item[101];
int ar[101][101];
int main(){
    FastIO;
    int n,m,r, maxi=0;cin>>n>>m>>r;
    for(int i=1;i<=n;i++){
        cin>>item[i];
        for(int j=1;j<=n;j++)ar[i][j]=1'000'000'000;
    }
    for(int i=0;i<r;i++){
        int a,b,c;cin>>a>>b>>c;
        ar[a][b]=min(c,ar[a][b]);
        ar[b][a]=min(c,ar[b][a]);
    }
    for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
        if(i==j)continue;
        ar[i][j]=min(ar[i][j],ar[i][k]+ar[k][j]);
    }
    for(int i=1;i<=n;i++){
        int sum=item[i];
        for(int j=1;j<=n;j++){
            if(ar[i][j]<=m)sum+=item[j];
        }
        maxi=max(maxi,sum);
    }
    cout<<maxi;
    return 0;
}