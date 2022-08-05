#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int main(){
    FastIO;
    int a[10'001]={0,};
    a[2]=1;
    for(int i=2;i<10001;i++){
        int x=i, s=i;
        while(x){
            s+=x%10;
            x/=10;
        }
        if(s>10000)continue;
        a[s]=1;
    }
    for(int i=1;i<10001;i++){
        if(!a[i])cout<<i<<'\n';
    }
    return 0;
}