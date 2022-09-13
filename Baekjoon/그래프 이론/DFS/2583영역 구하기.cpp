#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int M,N,K, cnt=1;
bool ar[101][101]={false,};
bool visited[101][101]={false,};
void dfs(int x, int y){
    for(int k=0;k<4;k++){
        int nx=x+"1012"[k]-'1';
        int ny=y+"2101"[k]-'1';
        if(nx<0 || ny<0 || nx>=M || ny>=N
        || ar[nx][ny] || visited[nx][ny])
            continue;
        visited[nx][ny]=true;
        cnt++;
        dfs(nx,ny);
    }
}
int main(){
    FastIO;
    cin>>N>>M>>K;
    vector<int> ans;
    for(int i=0;i<K;i++){
        int a,b,c,d;cin>>a>>b>>c>>d;
        for(int j=a;j<c;j++)for(int k=b;k<d;k++)ar[j][k]=true;
    }
    for(int i=0;i<M;i++)for(int j=0;j<N;j++){
        if(ar[i][j] || visited[i][j])continue;
        cnt=1, visited[i][j]=true;
        dfs(i,j);
        ans.push_back(cnt);
    }
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<'\n';
    for(auto i:ans)cout<<i<<" ";
    return 0;
}