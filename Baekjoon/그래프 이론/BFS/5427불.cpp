#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

char ar[1000][1000];
bool visited[1000][1000];
int main(){
    FastIO;
    int T;cin>>T;
    while(T--){
        int w,h, cnt=0;cin>>w>>h;
        queue<pair<int,int>> q_sangeun;
        queue<pair<int,int>> q_fire;
        for(int i=0;i<h;i++)for(int j=0;j<w;j++){
            cin>>ar[i][j];
            visited[i][j]=false;
            if(ar[i][j]=='@') {
                q_sangeun.push({i, j});
                visited[i][j]=true;
            }
            if(ar[i][j]=='*')q_fire.push({i,j});
        }
        while(true) {
            int q_fire_size = q_fire.size();
            int q_sangeun_size = q_sangeun.size();
            bool flag = false;
            while (q_fire_size--) {
                auto [x, y] = q_fire.front();q_fire.pop();
                for (int k = 0; k < 4; k++) {
                    int nx = x + "1012"[k] - '1';
                    int ny = y + "2101"[k] - '1';
                    if (nx < 0 || ny < 0 || nx >= h || ny >= w
                        || ar[nx][ny] == '#' || ar[nx][ny]=='*')
                        continue;
                    ar[nx][ny] = '*';
                    q_fire.push({nx, ny});
                }
            }
            while (q_sangeun_size-- && !flag) {
                auto [x, y] = q_sangeun.front();q_sangeun.pop();
                for (int k = 0; k < 4; k++) {
                    int nx = x + "1012"[k] - '1';
                    int ny = y + "2101"[k] - '1';
                    if (nx < 0 || ny < 0 || nx >= h || ny >= w){
                        flag = true;
                        break;
                    }
                    if (ar[nx][ny] == '#' || ar[nx][ny] == '*' || visited[nx][ny]) continue;
                    ar[nx][ny] = '@';
                    visited[nx][ny]=true;
                    q_sangeun.push({nx, ny});
                }
            }
            cnt++;
            if(flag){
                cout<<cnt<<'\n';
                break;
            }
            if(q_sangeun.empty()){
                cout<<"IMPOSSIBLE\n";
                break;
            }
        }
    }
    return 0;
}