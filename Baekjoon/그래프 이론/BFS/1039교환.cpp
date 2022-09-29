#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

string swit(string s, int i, int j){
    char tmp=s[i];
    s[i]=s[j];
    s[j]=tmp;
    return s;
}
int main(){
    FastIO;
    int N,K, maxi=0;cin>>N>>K;
    if(N<=10){
        cout<<-1;
        return 0;
    }
    queue<pair<string,int>> q;
    set<string> visited[11];
    q.push({to_string(N),0});
    while(!q.empty()){
        auto [cur, cnt]=q.front();q.pop();
        for(int i=0;i<cur.length()-1;i++){
            for(int j=i+1;j<cur.length();j++){
                if(i==0 && cur[j]=='0')continue;
                string result=swit(cur,i,j);
                if(visited[cnt+1].count(result))continue;
                if(cnt+1==K){
                    maxi=max(maxi,stoi(result));
                    continue;
                }
                visited[cnt+1].insert(result);
                q.push({result, cnt+1});
            }
        }
    }
    if(maxi)cout<<maxi;
    else cout<<-1;
    return 0;
}