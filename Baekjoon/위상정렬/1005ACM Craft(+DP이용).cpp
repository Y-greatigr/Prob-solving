#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int ar[1'001];  // 건설에 걸리는 시간 배열
int dp[1'001];  // i번째까지 걸리는 시간 배열
int cnt[1'001]; // 위상정렬을 위한 배열
vector<int> v[1'001];   // 후위 배열
int main(){
    FastIO;
    int T;cin>>T;
    while(T--){
        int N,K, des;cin>>N>>K;
        for(int i=1;i<=N;i++){  // 초기화
            cin>>ar[i];
            cnt[i]=0;
            dp[i]=0;
            v[i].clear();
        }
        while(K--){ // 규칙
            int a,b;cin>>a>>b;
            v[a].push_back(b);
            cnt[b]++;
        }
        cin>>des;
        queue<int> q;
        for(int i=1;i<=N;i++){  // 초기에 건설 가능한 것들
            if(!cnt[i]){
                q.push(i);
                dp[i]=ar[i];
            }
        }
        while(!q.empty()){
            int cur=q.front();q.pop();
            for(int i=0;i<v[cur].size();i++){
                cnt[v[cur][i]]--;
                dp[v[cur][i]]=max(dp[cur]+ar[v[cur][i]], dp[v[cur][i]]);    // dp
                if(!cnt[v[cur][i]]){
                    q.push(v[cur][i]);
                }
            }
        }
        cout<<dp[des]<<'\n';
    }
    return 0;
}