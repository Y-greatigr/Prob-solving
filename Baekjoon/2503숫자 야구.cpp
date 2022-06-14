#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int main(){
    FastIO;
    int n, sum=0;cin>>n;
    bool ar[1000]={false, };
    while(n--){
        int num,strike,ball;cin>>num>>strike>>ball;
        int a=num/100, b=(num/10)%10, c=num%10;
        for(int i=1;i<=9;i++)for(int j=1;j<=9;j++)for(int k=1;k<=9;k++){
            if(i==j || i==k || j==k)continue;
            int strike_sum=0, ball_sum=0;
            if(a==i)strike_sum++;
            if(b==j)strike_sum++;
            if(c==k)strike_sum++;
            if(a==j || a==k)ball_sum++;
            if(b==i || b==k)ball_sum++;
            if(c==j || c==i)ball_sum++;
            if(strike_sum!=strike || ball_sum!=ball)ar[100*i+10*j+k]=true;
        }
    }
    for(int i=1;i<=9;i++)for(int j=1;j<=9;j++)for(int k=1;k<=9;k++){
        if(i==j || i==k || j==k)continue;
        if(!ar[100*i+10*j+k])sum++;
    }
    cout<<sum;
    return 0;
}