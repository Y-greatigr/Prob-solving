#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

char boo[10];
int visited[10]={false, };
string maxi="0", mini= "9876543210";

void dfs(int cur, int n, string ss){
    if(cur==n){
        if(stoll(ss)<stoll(mini))mini=ss;
        if(stoll(ss)>stoll(maxi))maxi=ss;
        return;
    }
    for(int i=0;i<10;i++){
        if(visited[i] || (cur>0 && boo[cur-1]=='<' && ss[cur-1]-'0'>i)
           || (cur>0 && boo[cur-1]=='>' && ss[cur-1]-'0'<i))continue;
        visited[i]= true;
        dfs(cur+1, n, ss+to_string(i));
        visited[i]= false;
    }
}
int main(){
    FastIO;
    int n;cin>>n;
    for(int i=0;i<2*n-1;i++){
        if(i%2)continue;
        cin>>boo[i/2];
    }
    dfs(0, n+1, "");
    cout<<maxi<<'\n';
    cout<<mini;
    return 0;
}