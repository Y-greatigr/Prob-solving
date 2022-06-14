#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

bool flag=true;
vector<int> v(9);
bool visited[9]={false, };
void dfs(int cur){
    if(cur==7){
        int sum=0;
        for(int i=0;i<9;i++){
            if(visited[i])sum+=v[i];
        }
        if(sum==100){
            for(int i=0;i<9;i++){
                if(visited[i])cout<<v[i]<<'\n';
            }
            flag= false;
        }
        return;
    }
    for(int i=0;i<9;i++){
        if(visited[i])continue;
        visited[i]=true;
        dfs(cur+1);
        if(!flag)return;
        visited[i]= false;
    }

}
int main(){
    FastIO;
    for(int i=0;i<9;i++)cin>>v[i];
    sort(v.begin(),v.end());
    dfs(0);
    return 0;
}