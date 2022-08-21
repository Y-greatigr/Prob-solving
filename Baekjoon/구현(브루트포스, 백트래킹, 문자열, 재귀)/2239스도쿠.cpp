#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int ar[9][9];
bool row[9][10]={false,};
bool col[9][10]={false,};
bool square[9][10]={false,};

bool dfs(int cur){
    if(cur==81){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout<<ar[i][j];
            }
            cout<<'\n';
        }
        return true;
    }

    int x=cur/9;
    int y=cur%9;

    if(ar[x][y]) return dfs(cur+1);
    else{
        for(int i=1;i<=9;i++){
            if(row[x][i] || col[y][i] || square[(x/3)*3+y/3][i])continue;
            row[x][i] = col[y][i] = square[(x/3)*3+y/3][i]=true;
            ar[x][y]=i;
            if(dfs(cur+1)) return true;
            row[x][i] = col[y][i] = square[(x/3)*3+y/3][i]= false;
            ar[x][y]=0;
        }
    }
    return false;
}
int main(){
    FastIO;
    for(int i=0;i<9;i++){
        string s;cin>>s;
        for(int j=0;j<9;j++){
            ar[i][j]=s[j]-'0';
            if(ar[i][j]){
                row[i][ar[i][j]]=true;
                col[j][ar[i][j]]=true;
                square[(i/3)*3+j/3][ar[i][j]]=true;
            }
        }
    }
    dfs(0);
    return 0;
}