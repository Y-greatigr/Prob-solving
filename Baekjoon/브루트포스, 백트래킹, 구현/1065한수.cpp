#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int main(){
    FastIO;
    int n, sum=0;cin>>n;
    for(int i=1;i<=n;i++){
        int k=i, pre=k%10, flag=1, dif=(k/10)%10-pre;
        pre=(k/10)%10, k/=100;
        while(k){
            int a=k%10;
            if(a-pre!=dif){
                flag=0;
                break;
            }
            pre=a;
            k/=10;
        }
        if(flag)sum++;
    }
    cout<<sum;
    return 0;
}