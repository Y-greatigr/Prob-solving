#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int main(){
    FastIO;
    int w,h,x,y,p, sum=0;cin>>w>>h>>x>>y>>p;
    while(p--){
        int a,b;cin>>a>>b;
        if(pow(a-x,2)+pow(y+h/2-b,2)<=pow(h/2,2)    // 왼쪽 원 안
        || (a>=x && a<=x+w && b>=y && b<=y+h)                       // 직사각형 안
        || pow(x+w-a,2)+pow(y+h/2-b,2)<= pow(h/2,2))// 오른쪽 원 안
            sum++;
    }
    cout<<sum;
    return 0;
}