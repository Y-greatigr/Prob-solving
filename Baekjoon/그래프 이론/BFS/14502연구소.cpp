#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int a[8][8];
int n,m;

int bfs(){
    int sum=0;
    int k[8][8]={0};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]!=2 || k[i][j]) continue;
            queue<pair<int,int>> q;
            q.push({i,j});
            k[i][j]=1;
            while(!q.empty()){
                auto cur=q.front();q.pop();
                for(int p=0;p<4;p++){
                    int nx=cur.first+"1012"[p]-'1';
                    int ny=cur.second+"2101"[p]-'1';
                    if(nx<0 || ny<0 || nx>=n || ny>=m || k[nx][ny]==1 || a[nx][ny]==2)continue;
                    if(a[nx][ny]==1) {
                        k[nx][ny]=1;
                        continue;
                    }
                    k[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(k[i][j]==1)continue;
            if(a[i][j]==1)continue;
            sum++;
        }
    }
    return sum;
}
int main(){
    FastIO;
    cin>>n>>m;
    int maxi=0;
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            if(!a[i][j]) v.push_back({i,j});
        }
    }
    for(int i=0;i<v.size();i++){
        for(int j=i+1;j<v.size();j++){
            for(int k=j+1;k<v.size();k++){
                a[v[i].first][v[i].second]=1;
                a[v[j].first][v[j].second]=1;
                a[v[k].first][v[k].second]=1;
                maxi=max(bfs(),maxi);
                a[v[i].first][v[i].second]=0;
                a[v[j].first][v[j].second]=0;
                a[v[k].first][v[k].second]=0;
            }
        }
    }
    cout<<maxi;
    return 0;
}
