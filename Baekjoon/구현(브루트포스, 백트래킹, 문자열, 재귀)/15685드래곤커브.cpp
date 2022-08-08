#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int a[101][101]={0,};

void draw(int y, int x, int d, int g){
    vector<int> v;
    v.push_back(d);
    int st=0;
    while(g--){
        for(int i=st; i<v.size();i++){
            y=y+"1012"[v[i]]-'1';
            x=x+"2101"[v[i]]-'1';
            a[y][x]=1;
        }
        st=v.size();
        for(int i=v.size()-1; i>=0;i--)v.push_back((v[i]+1)%4);
    }
}
int main(){
    FastIO;
    int n, sum=0;cin>>n;
    while(n--){
        int x,y,d,g;cin>>x>>y>>d>>g;
        a[y][x]=1;
        draw(y,x,d,g+1);
    }
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            if(a[i][j] &&a[i][j+1] &&a[i+1][j] &&a[i+1][j+1])sum++;
        }
    }
    cout<<sum;
    return 0;
}