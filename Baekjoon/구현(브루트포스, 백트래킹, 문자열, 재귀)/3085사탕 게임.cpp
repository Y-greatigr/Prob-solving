#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int n;
char ar[50][50];
int check(){
    int maximum=0;
    int maxi[50][50];
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)maxi[i][j]=1;
    for(int i=1;i<n;i++)for(int j=0;j<n;j++){
        if(ar[i][j]==ar[i-1][j]){
            maxi[i][j]=maxi[i-1][j]+1;
            maximum=max(maxi[i][j],maximum);
            if(maximum==n) return n;
        }
    }
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)maxi[i][j]=1;
    for(int i=1;i<n;i++)for(int j=0;j<n;j++){
        if(ar[j][i]==ar[j][i-1]){
            maxi[j][i]=maxi[j][i-1]+1;
            maximum=max(maxi[j][i],maximum);
            if(maximum==n) return n;
        }
    }
    return maximum;
}
int check(int r, int c, int x, int y){
    int maximum=0;
    int maxi[50][50];
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)maxi[i][j]=1;
    for(int i=1;i<n;i++){
        if(ar[i][c]==ar[i-1][c]){
            maxi[i][c]=maxi[i-1][c]+1;
            maximum=max(maximum,maxi[i][c]);
        }
        if(c!=y && ar[i][y]==ar[i-1][y]){
            maxi[i][y]=maxi[i-1][y]+1;
            maximum=max(maximum,maxi[i][y]);
        }
    }
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)maxi[i][j]=1;
    for(int i=1;i<n;i++){
        if(ar[r][i]==ar[r][i-1]){
            maxi[r][i]=maxi[r][i-1]+1;
            maximum=max(maximum,maxi[r][i]);
        }
        if(r!=x && ar[x][i]==ar[x][i-1]){
            maxi[x][i]=maxi[x][i-1]+1;
            maximum=max(maximum,maxi[x][i]);
        }
    }
    return maximum;
}
int main(){
    FastIO;
    int maxim=0;
    cin>>n;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>ar[i][j];
    maxim=max(check(),maxim);
    if(maxim==n){
        cout<<n;
        return 0;
    }
    for(int i=0;i<n;i++)for(int j=0;j<n;j++){
        for(int k=0;k<4;k++){
            int nx=i+"1012"[k]-'1';
            int ny=j+"2101"[k]-'1';
            if(nx<0 || ny<0 || nx>=n || ny>=n || ar[i][j]==ar[nx][ny])continue;
            char c = ar[i][j];
            char b=ar[nx][ny];
            ar[i][j]=b,ar[nx][ny]=c;
            maxim=max(check(i,j,nx,ny), maxim);
            if(maxim==n){
                cout<<n;
                return 0;
            }
            ar[i][j]=c,ar[nx][ny]=b;
        }
    }
    cout<<maxim;
    return 0;
}