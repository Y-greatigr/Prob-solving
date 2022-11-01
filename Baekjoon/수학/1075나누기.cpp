#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int main(){
    FastIO;
    int n,f;cin>>n>>f;
    int tmp=n/100;tmp*=100;
    tmp%=f;
    if(!tmp){
        cout<<"00";
        return 0;
    }
    tmp=f-tmp;
    if(tmp<10)cout<<'0'<<tmp;
    else cout<<tmp;
    return 0;
}