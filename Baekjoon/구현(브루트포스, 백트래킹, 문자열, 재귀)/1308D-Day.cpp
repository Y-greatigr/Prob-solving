#include <bits/stdc++.h>
#define FastIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;

int ar[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
bool is_yun(int y){
    if(y%4!=0)return false;
    if(y%400==0)return true;
    if(y%100==0)return false;
    return true;
}
int main(){
    FastIO;
    int to_y, to_m, to_d, d_y, d_m, d_d;cin>>to_y>>to_m>>to_d>>d_y>>d_m>>d_d;
    if((d_y-to_y>1000) || ((d_y-to_y==1000) && (to_m<d_m || (to_m==d_m && to_d<=d_d)))){
        cout<<"gg";
        return 0;
    }

    int sum=0;
    for(int i=to_y+1;i<d_y;i++){
        if(is_yun(i))sum+=366;
        else sum+=365;
    }

    if(to_y!=d_y){
        for(int i=to_m+1;i<=12;i++){
            sum+=ar[i];
            if(i==2 && is_yun(to_y))sum++;
        }
        sum+=ar[to_m]-to_d;
        if(to_m==2 && is_yun(to_y))sum++;

        for(int i=1;i<d_m;i++){
            sum+=ar[i];
            if(i==2 && is_yun(d_y))sum++;
        }
        sum+=d_d;
    }
    else{
        for(int i=to_m+1;i<d_m;i++){
            sum+=ar[i];
            if(i==2 && is_yun(to_y))sum++;
        }
        if(to_m==d_m){
            sum+=d_d-to_d;
        }
        else{
            sum+=ar[to_m]-to_d;
            sum+=d_d;
            if(to_m==2 && is_yun(to_y))sum++;
        }
    }

    cout<<"D-"<<sum;
    return 0;
}