#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

char ar[100][100];
bool visited[100][100];
int main(){
    FastIO;
    int T;cin>>T;
    while(T--){
        int h,w, maxi=0;cin>>h>>w;
        vector<pair<int,int>> m[26];
        for(int i=0;i<h;i++)for(int j=0;j<w;j++){
            cin>>ar[i][j];
            visited[i][j]=false;
        }
        set<char> se;string s;cin>>s;
        for(auto i:s)se.insert(i);
        queue<pair<int,int>> q;
        for(int i=0;i<h;i++)for(int j=0;j<w;j++){
            if(!i || !j || i==h-1 || j==w-1) {
                if(ar[i][j]!='*'){
                    if(ar[i][j]>='A' && ar[i][j]<='Z' && !se.count((char)(ar[i][j]+32))){
                        m[ar[i][j]-'A'].push_back({i,j});
                        continue;
                    }
                    if(ar[i][j]=='$'){
                        maxi++;
                    }
                    else if(ar[i][j]>='a' && ar[i][j]<='z'){
                        se.insert(ar[i][j]);
                    }
                    visited[i][j]=true;
                    q.push({i, j});
                }
            }
        }
        while(!q.empty()){
            auto [x,y]=q.front();q.pop();
            for(int k=0;k<4;k++){
                int nx=x+"1012"[k]-'1';
                int ny=y+"2101"[k]-'1';
                if(nx<0 || ny<0 || nx>=h || ny>=w
                || ar[nx][ny]=='*' || visited[nx][ny])
                    continue;
                if(ar[nx][ny]>='A' && ar[nx][ny]<='Z' && !se.count((char)(ar[nx][ny]+32))){
                    m[ar[nx][ny]-'A'].push_back({nx,ny});
                    continue;
                }
                if(ar[nx][ny]>='a' && ar[nx][ny]<='z' && !se.count(ar[nx][ny])){
                    se.insert(ar[nx][ny]);
                    for(int i=0;i<m[ar[nx][ny]-32-'A'].size();i++){
                        q.push({m[ar[nx][ny]-32-'A'][i].first, m[ar[nx][ny]-32-'A'][i].second});
                        visited[m[ar[nx][ny]-32-'A'][i].first][m[ar[nx][ny]-32-'A'][i].second]=true;
                    }
                }
                else if(ar[nx][ny]=='$'){
                    maxi++;
                }
                visited[nx][ny]=true;
                q.push({nx,ny});
            }
        }
        cout<<maxi<<'\n';
    }
    return 0;
}