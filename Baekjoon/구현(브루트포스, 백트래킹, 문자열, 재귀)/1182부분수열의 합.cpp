#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int n, s, cnt=0;
int ar[20];
void dfs(int cur, int sum, int counting){
    if(cur==n){
        if(counting==0)return;
        if(sum==s)cnt++;
        return;
    }
    dfs(cur+1,sum+ar[cur], counting+1);
    dfs(cur+1, sum, counting);
}
int main(){
    FastIO;
    cin>>n>>s;
    for(int i=0;i<n;i++)cin>>ar[i];
    dfs(1, ar[0], 1);
    dfs(1, 0, 0);
    cout<<cnt;
    return 0;
}