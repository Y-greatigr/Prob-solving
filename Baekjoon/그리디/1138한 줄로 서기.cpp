#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int ar[10]={0,};
int main(){
    FastIO;
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        for(int j=0;j<n;j++){
            if(!a && !ar[j]){
                ar[j]=i+1;
                break;
            }
            else if(!ar[j])a--;
        }
    }
    for(int i=0;i<n;i++)cout<<ar[i]<<" ";
    return 0;
}