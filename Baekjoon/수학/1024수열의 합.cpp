#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int main(){
    FastIO;
    int N,L;cin>>N>>L;
    for(int i=L;i<=100;i++){
        if(N-(i*(i-1)/2)>=0 && !((N-(i*(i-1)/2)) % i)){
            for(int j=(N-(i*(i-1)/2)) / i;j<(N-(i*(i-1)/2))/i + i;j++){
                cout<<j<<" ";
            }
            return 0;
        }
    }
    cout<<-1;
    return 0;
}