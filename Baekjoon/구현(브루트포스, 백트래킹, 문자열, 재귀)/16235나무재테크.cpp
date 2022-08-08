#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int N,M,K;
int board[11][11];
int a[11][11];
deque<int> dq[11][11];
int main(){
    FastIO;
    cin>>N>>M>>K;
    for(int i=1;i<=N;i++)for(int j=1;j<=N;j++){cin>>a[i][j];board[i][j]=5;}
    for(int i=0;i<M;i++){
        int a,b,c;cin>>a>>b>>c;
        dq[a][b].push_back(c);
    }
    while(K--){
        queue<tuple<int,int,int>> q_dead;   // 봄에 죽는 것들
        for(int i=1;i<=N;i++){  // 봄
            for(int j=1;j<=N;j++){
                if(dq[i][j].size()>0){
                    for(int k=0;k<dq[i][j].size();k++){
                        if(dq[i][j][k]>board[i][j]){    // 죽은 아이들
                            while(k<dq[i][j].size()){
                                q_dead.push(make_tuple(i,j,dq[i][j].back()));
                                M--;
                                dq[i][j].pop_back();
                            }
                            break;
                        }
                        board[i][j]-=dq[i][j][k];
                        dq[i][j][k]++;
                    }
                }
            }
        }
        while(!q_dead.empty()){ // 여름
            board[get<0>(q_dead.front())][get<1>(q_dead.front())]+=get<2>(q_dead.front())/2;
            q_dead.pop();
        }
        for(int i=1;i<=N;i++){  // 봄
            for(int j=1;j<=N;j++){
                if(dq[i][j].empty())continue;
                for(int k=0;k<dq[i][j].size();k++){
                    if(dq[i][j][k]%5)continue;
                    for(int p=0;p<8;p++){
                        int nx=i+"00011222"[p]-'1';
                        int ny=j+"01202012"[p]-'1';
                        if(nx<1 || nx>N || ny<1 || ny>N)continue;
                        M++;
                        dq[nx][ny].push_front(1);
                    }
                }
            }
        }
        for(int i=1;i<=N;i++)for(int j=1;j<=N;j++)board[i][j]+=a[i][j]; // 겨울
    }
    cout<<M;
    return 0;
}