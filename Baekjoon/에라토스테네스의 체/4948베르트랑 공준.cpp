#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int main(){
    FastIO;
    int n;
    int *ar=new int[246913];
    memset(ar, 0, sizeof(int)*246913);
    for(int i=2;i<=123456;i++){
        for(int j=2;j<=123456;j++){
            if(i*j>246912)break;
            ar[i*j]=1;
        }
    }
    ar[1]=1;
    while(1){
        cin>>n;
        if(!n)break;
        int sum=0;
        for(int i=n+1;i<=2*n;i++){
            if(!ar[i])sum++;
        }
        cout<<sum<<'\n';
    }
    return 0;
}