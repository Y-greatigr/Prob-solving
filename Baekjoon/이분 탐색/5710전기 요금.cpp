#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int wh_to_price(int wh){
    int sum=0;
    if(wh>1'000'000) {
        sum+=(wh-1'000'000)*7;
        wh=1'000'000;
    }
    if(wh>10'000){
        sum+=(wh-10'000)*5;
        wh=10'000;
    }
    if(wh>100){
        sum+=(wh-100)*3;
        wh=100;
    }
    if(wh>0)sum+=wh*2;
    return sum;
}
int price_to_wh(int price){
    int sum=0;
    if(price>4'979'900){
        sum+=(price-4'979'900)/7;
        price=4'979'900;
    }
    if(price>29'900){
        sum+=(price-29'900)/5;
        price=29'900;
    }
    if(price>200){
        sum+=(price-200)/3;
        price=200;
    }
    if(price>0){
        sum+=price/2;
    }
    return sum;
}
int main(){
    FastIO;
    int a,b;cin>>a>>b;
    while(a!=0 || b!=0){
        int total_wh=price_to_wh(a);
        int left=1, right=total_wh;
        while(left<=right){
            int mid=(left+right)/2;
            int s= wh_to_price(mid), n=wh_to_price(total_wh-mid);
            if(n-s<b){
                right=mid-1;
            }
            else if(n-s>b){
                left=mid+1;
            }
            else if(n-s==b){
                cout<<s<<'\n';
                break;
            }
        }
        cin>>a>>b;
    }
    return 0;
}