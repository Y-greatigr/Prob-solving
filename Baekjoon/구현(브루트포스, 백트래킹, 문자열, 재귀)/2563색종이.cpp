#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int main(){
    FastIO;
    bool ar[100][100]={false,};
    int N, sum=0;cin>>N;
    while(N--){
        int x,y;cin>>x>>y;
        for(int i=x;i<x+10;i++)for(int j=y;j<y+10;j++)ar[i][j]=true;
    }
    for(int i=0;i<100;i++)for(int j=0;j<100;j++)if(ar[i][j])sum++;
    cout<<sum;
    return 0;
}