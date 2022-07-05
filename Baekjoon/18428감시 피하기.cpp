#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

char ar[6][6];
bool visited[6][6]={false,}, flag=false;
vector<pair<int,int>> teacher;
int n;

void dfs(int cur){
    if(cur==3){
        bool flag3=true;
        for(int i=0;i<teacher.size() && flag3;i++){
            int x=teacher[i].first;
            int y=teacher[i].second;
            bool flag2=true;
            for(int k=y-1;k>=0 && flag2;k--){
                if(ar[x][k]=='S'){
                    flag2=false;
                    break;
                }
                if(visited[x][k])break;
            }
            for(int k=y+1;k<n && flag2; k++){
                if(ar[x][k]=='S'){
                    flag2=false;
                    break;
                }
                if(visited[x][k])break;
            }
            for(int k=x+1;k<n && flag2; k++){
                if(ar[k][y]=='S'){
                    flag2=false;
                    break;
                }
                if(visited[k][y])break;
            }
            for(int k=x-1;k>=0 && flag2; k--){
                if(ar[k][y]=='S'){
                    flag2=false;
                    break;
                }
                if(visited[k][y])break;
            }
            if(!flag2)flag3=false;
        }
        if(flag3)flag=true;
        return;
    }
    for(int i=0;i<n;i++)for(int j=0;j<n;j++){
        if(ar[i][j]=='X' && !visited[i][j]){
            visited[i][j]=true;
            dfs(cur+1);
            if(flag)break;
            visited[i][j]=false;
        }
    }
}
int main(){
    FastIO;
    cin>>n;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++){
        cin>>ar[i][j];
        if(ar[i][j]=='T')teacher.push_back({i,j});
    }
    for(int i=0;i<n;i++)for(int j=0;j<n;j++){
        if(ar[i][j]=='X' && !visited[i][j]){
            visited[i][j]=true;
            dfs(1);
            if(flag)break;
            visited[i][j]=false;
        }
    }
    if(flag)cout<<"YES";
    else cout<<"NO";
    return 0;
}