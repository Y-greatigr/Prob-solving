#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int main(){
    FastIO;
    int N;cin>>N;
    double cnt=0;
    bool flag=false;
    for(int i=0;i<N;i++){
        char c;cin>>c;
        if(c=='S')cnt++;
        else{
            flag=true;
            cnt+=0.5;
        }
    }
    if(flag)cout<<cnt+1;
    else cout<<cnt;
    return 0;
}