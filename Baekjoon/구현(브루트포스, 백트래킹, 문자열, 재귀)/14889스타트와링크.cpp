#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int n;
int a[20][20];
int mini=INT_MAX;
bool visited[20]={false,};

void dfs(int cur, int cnt){
    if(cnt==n/2){
        int st=0, li=0;
        for(int i=0;i<n;i++)for(int j=0;j<n;j++){
            if(visited[i]&&visited[j])st+=a[i][j];
            if(!visited[i]&&!visited[j])li+=a[i][j];
        }
        mini=min(mini,abs(st-li));
        return;
    }
    for(int i=cur;i<n-1;i++){
        visited[i]=true;
        dfs(i+1,cnt+1);
        visited[i]=false;
    }
}
int main(){
    FastIO;
    cin>>n;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>a[i][j];
    dfs(0, 0);
    cout<<mini;
    return 0;
}
