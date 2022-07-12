#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int n;
set<int> s;

int rom[4]={1,5,10, 50};
int ar[4]={0,0,0,0};
void dfs(int cur, int cnt){
    if(cur==4){
        if(cnt<n)return;
        int sum=0;
        for(int i=0;i<4;i++){
            sum+=rom[i]*ar[i];
        }
        s.insert(sum);
        return;
    }
    for(int i=0;i+cnt<=n;i++){
        ar[cur]=i;
        dfs(cur+1, cnt+i);
        ar[cur]=0;
    }
}
int main(){
    FastIO;
    cin>>n;
    dfs(0, 0);
    cout<<s.size();
    return 0;
}