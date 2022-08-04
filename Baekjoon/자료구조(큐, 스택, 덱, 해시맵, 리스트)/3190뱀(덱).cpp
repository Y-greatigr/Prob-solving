#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int board[101][101]={0,};
int main(){
    FastIO;
    int N, K, L;cin>>N>>K;
    queue<pair<int, char>> m;
    while(K--){
        int a,b;cin>>a>>b;
        board[a][b]=1;
    }
    cin>>L;
    while(L--){
        int a;char c;cin>>a>>c;
        m.push({a,c});
    }
    deque<pair<int,int>> dq;        // 몸 배열
    queue<pair<pair<int,int>,pair<int,int>>> q; // 머리 위치 x,y, 시간, 방향(오:1, 아:2, 왼:3, 위:4)
    dq.push_back({1,1});    // 현재 몸 입력
    q.push({{1,1},{0,1}});  // 현재 머리, 시간, 방향 입력
    while(!q.empty()){
        auto head=q.front();q.pop();
        int k=head.second.second;
        if(head.second.first==m.front().first){
            if(m.front().second=='L'){k--;if(!k)k=4;}
            else{k++;if(k==5)k=1;}         
            m.pop();    
        }
        int x,y;
        if(k==1) x=head.first.first, y=head.first.second+1;
        else if(k==2) x=head.first.first+1, y=head.first.second;
        else if(k==3) x=head.first.first, y=head.first.second-1;
        else if(k==4) x=head.first.first-1, y=head.first.second;
        q.push({{x,y},{head.second.first+1,k}});
        if(x<1 || x>N || y<1 || y>N){cout<<head.second.first+1;return 0;}
        for(int i=0;i<dq.size();i++){
            if(x==dq[i].first && y==dq[i].second){cout<<head.second.first+1;return 0;}
        }
        dq.push_front({x,y});
        if(!board[head.first.first][head.first.second])dq.pop_back();
        else board[head.first.first][head.first.second]=0;
    }
    return 0;
}
