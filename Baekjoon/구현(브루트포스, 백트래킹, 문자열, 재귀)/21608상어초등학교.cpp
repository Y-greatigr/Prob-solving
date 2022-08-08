#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int ma[21][21]={0,};
int a[401][4]={0,};

int main(){
    FastIO;
    int n, total=0;cin>>n;
    queue<int> q;
    for(int i=1;i<=n*n;i++){
        int k;cin>>k;q.push(k);
        for(int j=0;j<4;j++)cin>>a[k][j];
    }
    while(!q.empty()){
        int cur=q.front();q.pop();
        int con3=-1, con4=-1, xx, yy;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(ma[i][j])continue;
                int con1=0, con2=0;
                for(int p=0;p<4;p++){
                    int x=i+"1012"[p]-'1';
                    int y=j+"2101"[p]-'1';
                    if(x<1 || y<1 || x>n || y>n)continue;
                    for(int q=0;q<4;q++)if(a[cur][q]==ma[x][y])con1++;
                    con2+=!ma[x][y];
                }
                if(con1>con3 || (con1==con3 && con2>con4)) xx=i, yy=j, con3=con1, con4=con2;
            }
        }
        ma[xx][yy]=cur;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int sum=0;
            for(int k=0;k<4;k++){
                int x=i+"1012"[k]-'1';
                int y=j+"2101"[k]-'1';
                if(x<1 || y<1 || x>n || y>n)continue;
                for(int p=0;p<4;p++)if(ma[x][y]==a[ma[i][j]][p]){sum++;continue;}
            }
            if(sum==2)total+=10;
            else if(sum==3)total+=100;
            else if(sum==4)total+=1000;
            else total+=sum;
        }
    }
    cout<<total;
    return 0;
}
