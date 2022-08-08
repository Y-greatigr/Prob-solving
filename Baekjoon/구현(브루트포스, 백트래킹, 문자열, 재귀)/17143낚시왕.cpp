#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

class shark{
public:
    int speed=0;
    int dir=0;
    int size=0;
    void clr(){speed=dir=size=0;}
};
shark a[100][100];
shark b[100][100];
int main(){
    FastIO;
    int R,C,M, sum=0;cin>>R>>C>>M;
    while(M--){
        int r,c,s,d,z;cin>>r>>c>>s>>d>>z;
        a[r-1][c-1].dir="01302"[d]-'0';
        a[r-1][c-1].speed=s%(((a[r-1][c-1].dir&1?R:C)-1)*2);
        a[r-1][c-1].size=z;
    }
    for(int j=0;j<C;j++){
        for(int i=0;i<R;i++) if(a[i][j].size){sum+=a[i][j].size;a[i][j].clr();break;}
        for(int i=0;i<R;i++)for(int jj=0;jj<C;jj++){
            if(!a[i][jj].size) continue;
            int speed=a[i][jj].speed;
            int nx=i,ny=jj;
            while(speed--){
                nx+="1012"[a[i][jj].dir]-'1';
                ny+="2101"[a[i][jj].dir]-'1';
                if(nx<0 || nx>=R || ny<0 || ny>=C){
                    a[i][jj].dir=(a[i][jj].dir+2)%4;
                    nx+=2*("1012"[a[i][jj].dir]-'1');
                    ny+=2*("2101"[a[i][jj].dir]-'1');
                }
            }
            if(b[nx][ny].size<a[i][jj].size)b[nx][ny]=a[i][jj];            
            a[i][jj].clr();
        }
        for(int i=0;i<R;i++)for(int jj=0;jj<C;jj++)a[i][jj]=b[i][jj], b[i][jj].clr();
    }  
    cout<<sum;
    return 0;
}