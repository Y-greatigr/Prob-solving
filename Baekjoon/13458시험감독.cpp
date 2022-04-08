#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int a[1'000'000];
int main(){
    FastIO;
    int n;cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    int b,c;cin>>b>>c;
    long long sum=0;
    for(int i=0;i<n;i++){
        if(a[i]-b<=0){sum++;continue;}
        if((a[i]-b)%c!=0)sum+=(a[i]-b)/c+2;
        else sum+=(a[i]-b)/c+1;
    }
    cout<<sum;
    return 0;
}
