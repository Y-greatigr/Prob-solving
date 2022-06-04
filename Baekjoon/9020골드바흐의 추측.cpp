#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int main(){
    FastIO;
    int t;cin>>t;
    int ar[10001]={0,};
    ar[1]=1;
    for(int i=2;i<5001;i++){
        for(int j=2;j<5001;j++){
            if(i*j>10000)break;
            ar[i*j]=1;
        }
    }
    while(t--){
        int n;cin>>n;
        if(!ar[n/2]){
            cout<<n/2<<" "<<n/2<<'\n';
            continue;
        }
        int left=n/2-1, right=n/2+1;
        while(left>=2 && right<=9998){
            if(!ar[left]&& !ar[right]){
                cout<<left<<" "<<right<<'\n';
                break;
            }
            left--,right++;
        }
    }
    return 0;
}