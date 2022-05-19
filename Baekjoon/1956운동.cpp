#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int main(){
    FastIO;
    int V,E, mini=INT_MAX;cin>>V>>E;
    int d[V][V];
    for(int i=0;i<V;i++)fill(d[i],d[i]+V,INT_MAX);
    while(E--){
        int a,b,c;cin>>a>>b>>c;
        d[a-1][b-1]=min(d[a-1][b-1], c);
    }
    for(int k=0;k<V;k++){
        for(int i=0;i<V;i++){
            if(i==k)continue;
            for(int j=0;j<V;j++){
                if(k==j || d[i][k]==INT_MAX || d[k][j]==INT_MAX)continue;
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
                if(i==j)mini=min(mini,d[i][j]);
            }
        }
    }
    cout<<(mini==INT_MAX?-1:mini);
    return 0;
}