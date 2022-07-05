#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int ar[10][10], paper[6]={0,5,5,5,5,5}, mini=25;
bool visited[10][10], flag=false;

void dfs(int cur){
    int x=-1,y=-1;
    for(int i=0;i<10 && x==-1;i++)for(int j=0;j<10;j++){
        if(ar[i][j] && !visited[i][j]){
            x=i,y=j;
            break;
        }
    }
    if(x==-1){
        mini=min(mini,cur);
        flag=true;
        return;
    }
    if(!paper[1] && !paper[2] && !paper[3] && !paper[4] && !paper[5])return;
    for(int k=1;k<=5;k++){
        if(!paper[k])continue;
        bool flag1=true;
        for(int nx=x;nx<x+k && flag1; nx++)for(int ny=y;ny<y+k; ny++){
            if(!ar[nx][ny] || visited[nx][ny] || nx>=10 || ny>=10){
                flag1= false;
                break;
            }
        }
        if(flag1){
            paper[k]--;
            for(int nx=x;nx<x+k && flag1; nx++)for(int ny=y;ny<y+k; ny++){
                visited[nx][ny]=true;
            }
            dfs(cur+1);
            paper[k]++;
            for(int nx=x;nx<x+k && flag1; nx++)for(int ny=y;ny<y+k; ny++){
                visited[nx][ny]= false;
            }
        }
    }
}
int main(){
    FastIO;
    bool flag_start=false;
    for(int i=0;i<10;i++)for(int j=0;j<10;j++){
        cin>>ar[i][j];
        if(ar[i][j])flag_start=true;
    }
    if(!flag_start){
        cout<<0;
        return 0;
    }
    dfs(0);
    if(flag)cout<<mini;
    else cout<<-1;
    return 0;
}