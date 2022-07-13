#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int main(){
    FastIO;
    int ar[101][101]={0,};
    map<int,tuple<int,int,int>> ma;
    int a,b,n,m;cin>>a>>b>>n>>m;
    for(int i=1;i<=n;i++){
        int c,d, k;
        char e;
        cin>>c>>d>>e;
        if(e=='E')k=3;  //S
        else if(e=='N')k=0; //E
        else if(e=='W')k=1; //N
        else if(e=='S')k=2; //W
        ar[c][d]=i;
        ma[i]={c,d,k};
    }
    while(m--){
        int c,d;
        char e;
        cin>>c>>e>>d;
        int x=get<0>(ma[c]);
        int y=get<1>(ma[c]);
        int k=get<2>(ma[c]);
        if(e=='L'){
            k=(k+d)%4;
            ma[c]={x,y,k};
        }
        else if(e=='R'){
            k=(k+(d*3))%4;
            ma[c]={x,y,k};
        }
        else{
            while(d--){
                int nx=x+"1012"[k]-'1';
                int ny=y+"2101"[k]-'1';
                if(nx<1 || ny<1 || nx>a || ny>b){
                    cout<<"Robot "<<c<<" crashes into the wall";
                    return 0;
                }
                if(ar[nx][ny]){
                    cout<<"Robot "<<c<<" crashes into robot "<<ar[nx][ny];
                    return 0;
                }
                ar[x][y]=0;
                ar[nx][ny]=c;
                ma[c]={nx,ny,k};
                x=nx,y=ny;
            }
        }
    }
    cout<<"OK";
    return 0;
}