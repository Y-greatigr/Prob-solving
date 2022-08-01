#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
char ar[500][500];
int main(){
    FastIO;
    int r,c;cin>>r>>c;
    bool flag= true;
    for(int i=0;i<r;i++)for(int j=0;j<c;j++)cin>>ar[i][j];
    for(int i=0;i<r && flag;i++)for(int j=0;j<c && flag;j++){
        if(ar[i][j]=='S'){
            for(int k=0;k<4;k++){
                int nx=i+"1012"[k]-'1';
                int ny=j+"2101"[k]-'1';
                if(nx<0 || ny<0 || nx>=r || ny>=c
                || ar[nx][ny]=='S')
                    continue;
                if(ar[nx][ny]=='W'){
                    flag=false;
                    break;
                }
                ar[nx][ny]='D';
            }
        }
    }
    if(flag){
        cout<<1<<'\n';
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++)cout<<ar[i][j];
            cout<<'\n';
        }
    }
    else cout<<0;
    return 0;
}