#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int ar[9][9];
vector<pair<int,int>> v;
bool flag=false;
bool check(int x, int y, int k){
    for(int i=0;i<9;i++){
        if(ar[i][y]==k)return false;
    }
    for(int j=0;j<9;j++){
        if(ar[x][j]==k)return false;
    }
    for(int i=(x/3)*3;i<(x/3+1)*3;i++){
        for(int j=(y/3)*3;j<(y/3+1)*3;j++){
            if(ar[i][j]==k)return false;
        }
    }
    return true;
}
void dfs(int cur){
    if(cur==v.size()){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++)cout<<ar[i][j]<<" ";
            cout<<'\n';
        }
        flag=true;
        return;
    }
    for(int k=1;k<10;k++){
        if(check(v[cur].first, v[cur].second, k)){
            ar[v[cur].first][v[cur].second]=k;
            dfs(cur+1);
            if(flag)return;
            ar[v[cur].first][v[cur].second]=0;
        }
    }
}
int main(){
    FastIO;
    for(int i=0;i<9;i++)for(int j=0;j<9;j++){
        cin>>ar[i][j];
        if(!ar[i][j])v.emplace_back(i,j);
    }
    dfs(0);
    return 0;
}