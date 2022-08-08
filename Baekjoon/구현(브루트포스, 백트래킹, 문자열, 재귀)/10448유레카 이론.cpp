#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int ar[50]={0,};
bool check[1001]={false, };
void init(){
    for(int i=1;i<50;i++)for(int j=1;j<50;j++)for(int k=1;k<50;k++){
        if(ar[i]+ar[j]+ar[k]<1001)
            check[ar[i]+ar[j]+ar[k]]= true;
    }
}
int main(){
    FastIO;
    for(int i=1;i<=50;i++)ar[i]=ar[i-1]+i;
    init();
    int n;cin>>n;
    while(n--){
        int a;cin>>a;
        cout<<(check[a]?1:0)<<'\n';
    }
    return 0;
}