#include <bits/stdc++.h>
#define FastIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;

int ar[100'001];
bool prime[100'001]={false,};
int main(){
    FastIO;
    int a,b, sum=0;cin>>a>>b;
    prime[1]=true;
    for(int i=2;i*i<=100'000;i++) {
        if (!prime[i]) {
            for (int j = i*i; j <= 100'000; j+=i) prime[j] = true;
        }
    }
    for(int i=2;i<=100'000;i++){
        if(prime[i])ar[i]=100'000'000;
        else ar[i]=1;
    }
    for(int i=2;i<=50'000;i++){
        for(int j=2;j*i<=100'000;j++){
            ar[i*j]=min(ar[i*j], ar[i]+ar[j]);
        }
    }
    for(int i=a;i<=b;i++){
        if(ar[i]==1)continue;
        if(!prime[ar[i]])sum++;
    }
    cout<<sum;
    return 0;
}