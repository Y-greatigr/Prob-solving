#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int ar[11], ope[4];
int n, maxi=-1'000'000'000, mini=1'000'000'000;
int oper(int i, int sum, int way){
    if(way==0)return sum+ar[i];
    else if(way==1)return sum-ar[i];
    else if(way==2)return sum*ar[i];
    else if(way==3)return sum/ar[i];
}
void dfs(int cnt, int sum){
    if(cnt==n-1){
        maxi=max(sum,maxi);
        mini=min(sum,mini);
        return;
    }
    for(int i=0;i<4;i++){
        if(!ope[i])continue;
        ope[i]--;
        dfs(cnt+1, oper(cnt+1, sum,i));
        ope[i]++;
    }
}
int main(){
    FastIO;
    cin>>n;
    for(int i=0;i<n;i++)cin>>ar[i];
    for(int i=0;i<4;i++)cin>>ope[i];
    dfs(0, ar[0]);
    cout<<maxi<<'\n'<<mini;
    return 0;
}