#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std;

int t[5][8];
void lt(int i){
    int tmp=t[i][0];
    for(int j=0;j<7;j++)t[i][j]=t[i][j+1];
    t[i][7]=tmp;
}
void rt(int i){
    int tmp=t[i][7];
    for(int j=7;j>0;j--)t[i][j]=t[i][j-1];
    t[i][0]=tmp;
}
int main(){
    FastIO;
    int K, sum=0;
    string str[5];
    for(int i=1;i<5;i++)cin>>str[i];
    for(int i=1;i<5;i++)for(int j=0;j<8;j++)t[i][j]=str[i][j]-'0';
    cin>>K;
    while(K--){
        int a,b;cin>>a>>b;
        if(a==1){
            if(t[1][2]!=t[2][6]){
                if(t[2][2]!=t[3][6]){
                    if(t[3][2]!=t[4][6]){
                        if(b==1)lt(4);
                        else rt(4);
                    }
                    if(b==1)rt(3);
                    else lt(3);
                }
                if(b==1)lt(2);
                else rt(2);
            }
            if(b==1)rt(1);
            else lt(1);
        }
        else if(a==2){
            if(t[1][2]!=t[2][6]){
                if(b==1)lt(1);
                else rt(1);
            }
            if(t[2][2]!=t[3][6]){
                if(t[3][2]!=t[4][6]){
                    if(b==1)rt(4);
                    else lt(4);
                }
                if(b==1)lt(3);
                else rt(3);
            }
            if(b==1)rt(2);
            else lt(2);
        }
        else if(a==3){
            if(t[3][2]!=t[4][6]){
                if(b==1)lt(4);
                else rt(4);
            }
            if(t[2][2]!=t[3][6]){
                if(t[1][2]!=t[2][6]){
                    if(b==1)rt(1);
                    else lt(1);
                }
                if(b==1)lt(2);
                else rt(2);
            }
            if(b==1)rt(3);
            else lt(3);
        }
        else{
            if(t[3][2]!=t[4][6]){
                if(t[2][2]!=t[3][6]){
                    if(t[1][2]!=t[2][6]){
                        if(b==1)lt(1);
                        else rt(1);
                    }
                    if(b==1)rt(2);
                    else lt(2);
                }
                if(b==1)lt(3);
                else rt(3);
            }
            if(b==1)rt(4);
            else lt(4);
        }
    }
    for(int i=1;i<5;i++)sum+=(t[i][0]*pow(2,(i-1)));
    cout<<sum;
    return 0;
}
