#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int main(){
    FastIO;
    vector<int> v(5);
    for(int i=0;i<5;i++)cin>>v[i];
    for(int i=1;i<1000000;i++){
        int cnt=0;
        for(int j=0;j<5;j++){
            if(i%v[j]==0)cnt++;
        }
        if(cnt>=3){
            cout<<i;
            break;
        }
    }
    return 0;
}