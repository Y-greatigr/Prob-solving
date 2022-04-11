#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int n, maxi=-1'000'000'000, mini=1'000'000'000;
int cal[4];
int num[11];

void dfs(int cur, int sum){
    if(cur==n-1){
        maxi=max(maxi, sum);
        mini=min(mini, sum);
        return;
    }
    if(cal[0])cal[0]--, dfs(cur+1, sum+num[cur+1]), cal[0]++;
    if(cal[1])cal[1]--, dfs(cur+1, sum-num[cur+1]), cal[1]++;
    if(cal[2])cal[2]--, dfs(cur+1, sum*num[cur+1]), cal[2]++;
    if(cal[3])cal[3]--, dfs(cur+1, sum/num[cur+1]), cal[3]++;
}
int main(){
    FastIO;
    cin>>n;
    for(int i=0;i<n;i++)cin>>num[i];
    for(int i=0;i<4;i++)cin>>cal[i];
    dfs(0, num[0]);
    cout<<maxi<<'\n'<<mini;
    return 0;
}
