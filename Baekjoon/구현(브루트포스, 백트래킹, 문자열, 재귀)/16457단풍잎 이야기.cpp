#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

bool visited[21]={false, };
vector<int> quest[100];
int maxi=0;

void dfs(int cur, int cnt, int n, int m, int k){
    if(cnt==n){
        int sum=0;
        for(int i=0;i<m;i++){
            bool flag=true;
            for(int j=0;j<k;j++){
                if(!visited[quest[i][j]]){
                    flag=false;
                    break;
                }
            }
            if(flag)sum++;
        }
        maxi=max(maxi,sum);
        return;
    }
    for(int i=cur;i<=2*n;i++){
        if(visited[i])continue;
        visited[i]=true;
        dfs(i+1, cnt+1, n, m, k);
        visited[i]=false;
    }
}
int main(){
    FastIO;
    int n,m,k;cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        for(int j=0;j<k;j++){
            int a;cin>>a;
            quest[i].push_back(a);
        }
    }
    dfs(1, 0, n, m, k);
    cout<<maxi;
    return 0;
}