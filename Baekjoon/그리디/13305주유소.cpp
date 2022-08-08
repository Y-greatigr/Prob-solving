#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

long long sum=0;
int main(){
    FastIO;
    int n;cin>>n;
    long long distance[n-1], price[n];
    for(int i=0;i<n-1;i++)cin>>distance[i];
    for(int i=0;i<n;i++)cin>>price[i];
    for(int i=0;i<n-1;i++){
        int j;
        sum+= distance[i]*price[i];
        for(j=i+1;j<n-1;j++){
            if(price[i]>=price[j])break;
            sum+=distance[j]*price[i];
        }
        i=j-1;
    }
    cout<<sum;
    return 0;
}