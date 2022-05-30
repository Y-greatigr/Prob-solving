#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

pair<char,int> ar[200][200];
int main(){
    FastIO;
    int R,C,N, cnt=1;cin>>R>>C>>N;
    for(int i=0;i<R;i++)for(int j=0;j<C;j++){
        char a;cin>>a;
        ar[i][j]={a,1};
    }
    while(cnt<N){
        bool visited[200][200]={false,};
        for(int i=0;i<R;i++)for(int j=0;j<C;j++){
            if(cnt%2 && ar[i][j].first=='.' && !visited[i][j]){
                ar[i][j]={'O',0};
                continue;
            }
            if(ar[i][j].second<2){
                ar[i][j].second++;
                continue;
            }
            ar[i][j]={'.',0};
            visited[i][j]=true;
            for(int k=0;k<4;k++){
                int nx=i+"1012"[k]-'1';
                int ny=j+"2101"[k]-'1';
                if(nx<0 || ny<0 || nx>=R || ny>=C || ar[nx][ny].second==2
                || visited[nx][ny] || ar[nx][ny].first=='.')continue;
                visited[nx][ny]=true;
                ar[nx][ny]={'.',0};
            }
        }
        cnt++;
    }
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++)cout<<ar[i][j].first;
        cout<<'\n';
    }
    return 0;
}