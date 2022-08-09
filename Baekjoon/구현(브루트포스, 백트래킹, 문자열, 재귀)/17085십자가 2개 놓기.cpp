#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int n,m;
char ar[15][15];
vector<tuple<int,int,int>> v;

bool make_corss(int step, int x, int y){
    if(ar[x][y]!='#')return false;
    for(int k=0;k<4;k++){
        int xx=x, yy=y;
        for(int s=0;s<step;s++){
            xx+="1012"[k]-'1';
            yy+="2101"[k]-'1';
            if(xx<0 || yy<0 || xx>=n || yy>=m
            || ar[xx][yy]!='#')return false;
        }
    }
    return true;
}
bool overlap_cross(tuple<int,int,int> a, tuple<int,int,int> b){
    bool visited[15][15]={false,};
    visited[get<1>(a)][get<2>(a)]=true;
    for(int k=0;k<4;k++){
        int xx=get<1>(a), yy=get<2>(a);
        for(int s=0;s<get<0>(a);s++){
            xx+="1012"[k]-'1';
            yy+="2101"[k]-'1';
            visited[xx][yy]=true;
        }
    }
    if(visited[get<1>(b)][get<2>(b)])return true;
    for(int k=0;k<4;k++){
        int xx=get<1>(b), yy=get<2>(b);
        for(int s=0;s<get<0>(b);s++){
            xx+="1012"[k]-'1';
            yy+="2101"[k]-'1';
            if(visited[xx][yy])return true;
        }
    }
    return false;
}
int width(int step1, int step2){
    return (step1*4+1)*(step2*4+1);
}
int main(){
    FastIO;
    int maxi=1;
    cin>>n>>m;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>ar[i][j];
    for(int i=0;i<n;i++)for(int j=0;j<m;j++){
        for(int step=0; make_corss(step,i,j);step++){
            v.push_back({step,i,j});
        }
    }
    for(int i=0;i<v.size()-1;i++)for(int j=i+1;j<v.size();j++){
        if(!overlap_cross(v[i],v[j])){
            maxi=max(maxi, width(get<0>(v[i]),get<0>(v[j])));
        }
    }
    cout<<maxi;
    return 0;
}