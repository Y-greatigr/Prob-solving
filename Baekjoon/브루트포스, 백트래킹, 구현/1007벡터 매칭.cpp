#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

vector<pair<double,double>> v;
bool visited[20]={false, };
double mini=(double)INT_MAX;
void dfs(int cur, int cnt, int half){
    if(cnt==half){
        double x1=0,x2=0,y1=0,y2=0;
        for(int i=0;i<half*2;i++){
            if(visited[i]){
                x1+=v[i].first;
                y1+=v[i].second;
            }
            else{
                x2+=v[i].first;
                y2+=v[i].second;
            }
        }
        mini=min(sqrt(pow(x1-x2,2)+pow(y1-y2,2)), mini);
        return;
    }
    for(int i=cur;i<half*2;i++){
        visited[i]=true;
        dfs(i+1, cnt+1, half);
        visited[i]=false;
    }
}
int main(){
    FastIO;
    int t;cin>>t;
    cout<<fixed;
    cout.precision(7);
    while(t--){
        int n;cin>>n;
        memset(visited, false, sizeof(visited));
        mini=(double)INT_MAX;
        v.clear();
        for(int i=0;i<n;i++){
            double a,b;cin>>a>>b;
            v.push_back({a,b});
        }
        dfs(0,0,n/2);
        cout<<mini<<'\n';
    }
    return 0;
}