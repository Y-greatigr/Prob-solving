#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int ar[10][1'000'000];
int main(){
    FastIO;
    int t;cin>>t;
    for(int i=2;i<10;i++){
        ar[i][1]=i;
        for(int j=2;j<1'000'000;j++){
            ar[i][j]=((ar[i][j-1])*i)%10;
        }
    }
    while(t--){
        int a,b;cin>>a>>b;
        if(!(a%10))cout<<10<<'\n';
        else if(a%10==1)cout<<1<<'\n';
        else cout<<ar[a%10][b]<<'\n';
    }
    return 0;
}