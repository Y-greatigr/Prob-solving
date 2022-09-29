#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int visited[100'000];
int click_b(int cur){
    string result = to_string(cur*2);
    result[0]--;
    return stoi(result);
}
int main(){
    FastIO;
    int N,T,G;cin>>N>>T>>G;
    if(N==G){
        cout<<0;
        return 0;
    }
    fill(visited, visited+100'000, 1'000'000'000);
    visited[N]=0;
    queue<int> q;
    q.push(N);
    while(!q.empty()){
        int cur=q.front();q.pop();
        if(cur+1<=99'999 && visited[cur+1]>visited[cur]+1 && visited[cur]+1<=T){
            visited[cur+1]=visited[cur]+1;
            if(cur+1==G){
                cout<<visited[G];
                return 0;
            }
            q.push(cur+1);
        }
        if(cur*2<=99'999 && cur){
            int next= click_b(cur);
            if(visited[next]>visited[cur]+1 && visited[cur]+1<=T){
                visited[next]=visited[cur]+1;
                if(next==G){
                    cout<<visited[G];
                    return 0;
                }
                q.push(next);
            }
        }
    }
    cout<<"ANG";
    return 0;
}