#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

char ar[1000][1000];
bool visited[1000][1000]={false,};
int main(){
    FastIO;
    int R,C, cnt=0;cin>>R>>C;
    queue<pair<int,int>> q_jihun;
    queue<pair<int,int>> q_fire;
    for(int i=0;i<R;i++)for(int j=0;j<C;j++){
        cin>>ar[i][j];
        if(ar[i][j]=='J') {
            q_jihun.push({i, j});
            visited[i][j]=true;
        }
        if(ar[i][j]=='F')q_fire.push({i,j});
    }
    while(true) {
        int q_fire_size = q_fire.size();
        int q_sangeun_size = q_jihun.size();
        bool flag = false;
        while (q_fire_size--) {
            auto [x, y] = q_fire.front();q_fire.pop();
            for (int k = 0; k < 4; k++) {
                int nx = x + "1012"[k] - '1';
                int ny = y + "2101"[k] - '1';
                if (nx < 0 || ny < 0 || nx >= R || ny >= C
                    || ar[nx][ny] == '#' || ar[nx][ny]=='F')
                    continue;
                ar[nx][ny] = 'F';
                q_fire.push({nx, ny});
            }
        }
        while (q_sangeun_size-- && !flag) {
            auto [x, y] = q_jihun.front();q_jihun.pop();
            for (int k = 0; k < 4; k++) {
                int nx = x + "1012"[k] - '1';
                int ny = y + "2101"[k] - '1';
                if (nx < 0 || ny < 0 || nx >= R || ny >= C){
                    flag = true;
                    break;
                }
                if (ar[nx][ny] == '#' || ar[nx][ny] == 'F' || visited[nx][ny]) continue;
                visited[nx][ny]=true;
                q_jihun.push({nx, ny});
            }
        }
        cnt++;
        if(flag){
            cout<<cnt<<'\n';
            break;
        }
        if(q_jihun.empty()){
            cout<<"IMPOSSIBLE\n";
            break;
        }
    }
    return 0;
}