#include <bits/stdc++.h>
#define FastIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;

int main(){
    FastIO;
    int n, cnt=0;cin>>n;
    while(n>10){
        bool flag=false;
        if(n%10>=5)flag=true;
        n/=10, cnt++;
        if(flag)n++;
    }
    cout<<((cnt>0)?(long long)pow(10,cnt)*n:n);
    return 0;
}