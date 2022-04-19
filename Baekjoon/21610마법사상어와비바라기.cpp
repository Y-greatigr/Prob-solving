#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int main(){
    FastIO;
    int n,m, sum=0;cin>>n>>m;
    int a[n+1][n+1], cloud[n+1][n+1]={0,};
    queue<pair<int,int>> q; q.push({n,1}),q.push({n,2}),q.push({n-1,1}),q.push({n-1,2});
    queue<pair<int,int>> dup_q;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)cin>>a[i][j];
    while(m--){
        int d,s;cin>>d>>s;
        while(!q.empty()){
            auto cl=q.front();q.pop();
            int x=cl.first+("010001222"[d]-'1')*s;
            int y=cl.second+("000122210"[d]-'1')*s;
            while(x<1)x+=n;while(x>n)x-=n;while(y<1)y+=n;while(y>n)y-=n;
            a[x][y]++;
            cloud[x][y]=1;
            dup_q.push({x,y});
        }
        while(!dup_q.empty()){
            auto cl=dup_q.front();dup_q.pop();
            for(int i=0;i<4;i++){
                int x=cl.first+"0022"[i]-'1';
                int y=cl.second+"0202"[i]-'1';
                if(x<1 || x>n || y<1 || y>n)continue;
                if(a[x][y])a[cl.first][cl.second]++;
            }        
        }
        for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
            if(a[i][j]>=2 && !cloud[i][j])q.push({i,j}), a[i][j]-=2;
            else if(cloud[i][j]) cloud[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)sum+=a[i][j];
    cout<<sum;
    return 0;
}
