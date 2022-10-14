#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int n, mini=1'000'000'000;
int ar[20][20], range[20][20];
map<int,int> m;
int calc(){
    for(int i=1;i<=5;i++)m[i]=0;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++){
        m[range[i][j]]+=ar[i][j];
    }
    int maxim=0, minim=1'000'000'000;
    for(int i=1;i<=5;i++){
        maxim=max(maxim,m[i]);
        minim=min(minim,m[i]);
    }
    return maxim-minim;
}
void divide_five(int x, int y, int d1, int d2){
    for(int x2=x, y2=y;x2<x+d2;x2++, y2++){
        for(int i=x2, j=y2; i<=x2+d1; i++, j--){
            range[i][j]=5;
            if(j!=y2-d1) range[i+1][j]=5;
        }
    }
    for(int i=x+d2, j=y+d2; i<=x+d2+d1; i++, j--)range[i][j]=5;
}
void divide_one(int x, int y, int d1){
    for(int i=0;i<x;i++)for(int j=0;j<=y;j++)range[i][j]=1;
    for(int i=x, cnt=y-1;i<x+d1;i++, cnt--)for(int j=0;j<=cnt;j++)range[i][j]=1;
}
void divide_two(int x, int y, int d2){
    for(int j=n-1;j>y+d2;j--)for(int i=0;i<=x+d2;i++)range[i][j]=2;
    for(int j=y+d2, cnt=x+d2-1;j>y;j--,cnt--)for(int i=0;i<=cnt;i++)range[i][j]=2;
}
void divide_three(int x, int y, int d1, int d2){
    for(int j=0;j<y-d1;j++)for(int i=x+d1;i<n;i++)range[i][j]=3;
    for(int j=y-d1, cnt=x+d1+1;j<y-d1+d2;j++,cnt++)for(int i=cnt;i<n;i++)range[i][j]=3;
}
void divide_four(int x, int y, int d1, int d2){
    for(int i=x+d1+d2+1;i<n;i++)for(int j=y-d1+d2;j<n;j++)range[i][j]=4;
    for(int i=x+d1+d2, cnt=n-(y-d1+d2)-1;i>x+d2;i--, cnt--)for(int j=n-1;j>n-1-cnt;j--)range[i][j]=4;
}
void divide(){
    for(int d1=1;d1<=n/2+1;d1++)for(int d2=1;d2<=n/2+1;d2++){
        for(int x=0;x<n;x++)for(int y=0;y<n;y++){
            if(x+d1+d2>=n || y-d1<0 || y+d2>=n) continue;
            divide_five(x, y, d1, d2);
            divide_one(x, y, d1);
            divide_two(x, y, d2);
            divide_three(x, y, d1, d2);
            divide_four(x, y, d1, d2);
            mini=min(mini,calc());
        }
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>ar[i][j];
    divide();
    cout<<mini;
    return 0;
}