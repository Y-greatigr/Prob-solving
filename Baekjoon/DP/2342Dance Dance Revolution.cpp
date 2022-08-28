#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

vector<int> v;
int n, k;
int dp[5][5][100'000];
int price(int from, int to){
    if(from==to)return 1;
    if(!from)return 2;
    if((from-to)%2)return 3;
    return 4;
}
int sol(int left, int right, int cnt){
    if(cnt==k)return 0;
    if(dp[left][right][cnt])return dp[left][right][cnt];
    return dp[left][right][cnt]=min(price(left, v[cnt])+sol(v[cnt],right,cnt+1)
            , price(right, v[cnt])+sol(left, v[cnt], cnt+1));
}
int main(){
    FastIO;
    while(cin>>n && n) v.push_back(n);
    k=v.size();
    cout<<sol(0,0,0);
    return 0;
}