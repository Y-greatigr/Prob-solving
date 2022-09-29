#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int visited[1'000'001]={0,};
int UD[2];
int main(){
    FastIO;
    int F,S,G;cin>>F>>S>>G>>UD[0]>>UD[1];
    if(S==G){
        cout<<0;
        return 0;
    }
    fill(visited, visited+F+1, 1'000'000'000);
    visited[S]=0;
    queue<int> q;
    q.push(S);
    while(!q.empty()){
        int cur=q.front();q.pop();
        for(int k=0;k<2;k++){
            int next=cur+("20"[k]-'1')*UD[k];
            if(next<=0 || next>F || visited[next]<=visited[cur]+1)continue;
            visited[next]=visited[cur]+1;
            if(next==G){
                cout<<visited[G];
                return 0;
            }
            q.push(next);
        }
    }
    cout<<"use the stairs";
    return 0;
}