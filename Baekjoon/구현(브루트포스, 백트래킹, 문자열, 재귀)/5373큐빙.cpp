#include <iostream>

using namespace std;

char cube[6][3][3];
char alpha[6]={'w', 'r', 'b', 'o', 'g', 'y'};
// 위 0 / 앞 1 / 오 2 / 뒤 3 / 왼 4 / 아 5
void rotate(int k){
    int temp[3][3];
    for(int i=0;i<3;i++)for(int j=0;j<3;j++){
        temp[i][j]=cube[k][j][2-i];
    }
    for(int i=0;i<3;i++)for(int j=0;j<3;j++){
        cube[k][i][j]=temp[i][j];
    }
}
void U(){
    int tmp[3];
    for(int i=0;i<3;i++){
        tmp[i]=cube[4][0][i];
    }
    for(int i=0;i<3;i++){
        for(int p=2;p>=0;p--)cube[2+p][0][i]=cube[1+p][0][i];
    }
    for(int i=0;i<3;i++)cube[1][0][i]=tmp[i];

    rotate(0);
}
void D(){
    int tmp[3];
    for(int i=0;i<3;i++){
        tmp[i]=cube[1][2][i];
    }
    for(int i=0;i<3;i++){
        for(int p=0;p<3;p++)cube[1+p][2][i]=cube[2+p][2][i];
    }
    for(int i=0;i<3;i++)cube[4][2][i]=tmp[i];

    rotate(5);
}
void F(){
    int tmp[3];

    tmp[0]=cube[4][0][2], tmp[1]=cube[4][1][2], tmp[2]=cube[4][2][2];

    cube[4][0][2]=cube[0][2][2], cube[4][1][2]=cube[0][2][1], cube[4][2][2]=cube[0][2][0];
    cube[0][2][2]=cube[2][2][0], cube[0][2][1]=cube[2][1][0], cube[0][2][0]=cube[2][0][0];
    cube[2][2][0]=cube[5][0][0], cube[2][1][0]=cube[5][0][1], cube[2][0][0]=cube[5][0][2];
    cube[5][0][0]=tmp[0], cube[5][0][1]=tmp[1], cube[5][0][2]=tmp[2];

    rotate(1);
}
void B(){
    int tmp[3];

    tmp[0]=cube[4][0][0], tmp[1]=cube[4][1][0], tmp[2]=cube[4][2][0];

    cube[4][0][0]=cube[5][2][0], cube[4][1][0]=cube[5][2][1], cube[4][2][0]=cube[5][2][2];
    cube[5][2][0]=cube[2][2][2], cube[5][2][1]=cube[2][1][2], cube[5][2][2]=cube[2][0][2];
    cube[2][2][2]=cube[0][0][2], cube[2][1][2]=cube[0][0][1], cube[2][0][2]=cube[0][0][0];
    cube[0][0][2]=tmp[0], cube[0][0][1]=tmp[1], cube[0][0][0]=tmp[2];

    rotate(3);
}
void L(){
    int tmp[3];

    tmp[0]=cube[1][0][0], tmp[1]=cube[1][1][0], tmp[2]=cube[1][2][0];

    cube[1][0][0]=cube[5][0][0], cube[1][1][0]=cube[5][1][0], cube[1][2][0]=cube[5][2][0];
    cube[5][0][0]=cube[3][2][2], cube[5][1][0]=cube[3][1][2], cube[5][2][0]=cube[3][0][2];
    cube[3][2][2]=cube[0][0][0], cube[3][1][2]=cube[0][1][0], cube[3][0][2]=cube[0][2][0];
    cube[0][0][0]=tmp[0], cube[0][1][0]=tmp[1], cube[0][2][0]=tmp[2];

    rotate(4);
}
void R(){
    int tmp[3];

    tmp[0]=cube[1][0][2], tmp[1]=cube[1][1][2], tmp[2]=cube[1][2][2];

    cube[1][0][2]=cube[0][0][2], cube[1][1][2]=cube[0][1][2], cube[1][2][2]=cube[0][2][2];
    cube[0][0][2]=cube[3][2][0], cube[0][1][2]=cube[3][1][0], cube[0][2][2]=cube[3][0][0];
    cube[3][2][0]=cube[5][0][2], cube[3][1][0]=cube[5][1][2], cube[3][0][0]=cube[5][2][2];
    cube[5][0][2]=tmp[0], cube[5][1][2]=tmp[1], cube[5][2][2]=tmp[2];

    rotate(2);
}
int main(){
    int t;cin>>t;
    while(t--){
        for(int i=0;i<6;i++)for(int j=0;j<3;j++)for(int k=0;k<3;k++)cube[i][j][k]=alpha[i];
        int n;cin>>n;
        for(int i=0;i<n;i++){
            string a;cin>>a;
            if(a[0]=='U'){
                if(a[1]=='-')U();
                else U(),U(),U();
            }
            else if(a[0]=='D'){
                if(a[1]=='-')D();
                else D(),D(),D();
            }
            else if(a[0]=='F'){
                if(a[1]=='-')F();
                else F(),F(),F();
            }
            else if(a[0]=='B'){
                if(a[1]=='-')B();
                else B(),B(),B();
            }
            else if(a[0]=='L'){
                if(a[1]=='-')L();
                else L(),L(),L();
            }
            else if(a[0]=='R'){
                if(a[1]=='-')R();
                else R(),R(),R();
            }
        }
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++)cout<<cube[0][j][k];
            cout<<'\n';
        }
    }
    return 0;
}