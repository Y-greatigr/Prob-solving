#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int main(){
    FastIO;
    char ar[8][8];
    int sum=0;
    for(int i=0;i<8;i++)for(int j=0;j<8;j++){
        char c;cin>>c;
        if((i+j)%2==0 && c=='F')sum++;
    }
    cout<<sum;
    return 0;
}