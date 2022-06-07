#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int main(){
    FastIO;
    int a,b, sum=0, mini=10'001;cin>>a>>b;
    int *ar=new int[10'001];
    memset(ar, 0, sizeof(int)*10'001);
    for(int i=2;i<=5000;i++){
        for(int j=2;j<=5000;j++){
            if(i*j>10000)break;
            ar[i*j]=1;
        }
    }
    ar[1]=1;
    for(int i=a;i<=b;i++){
        if(!ar[i]){
            mini=min(i,mini);
            sum+=i;
        }
    }
    if(!sum)cout<<-1;
    else cout<<sum<<'\n'<<mini;
    return 0;
}