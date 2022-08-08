#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int a[100][100];
int main(){
    FastIO;
    int N,L, cnt=0;cin>>N>>L;
    for(int i=0;i<N;i++)for(int j=0;j<N;j++)cin>>a[i][j];
    for(int i=0;i<N;i++){
        bool flag=true;
        int k=-1;
        for(int j=1;j<N;j++){
            if(abs(a[i][j]-a[i][j-1])>1){flag=false; break;}
            if(a[i][j]==a[i][j-1])continue;
            if(a[i][j]>a[i][j-1]){
                if(j-1-k<L){flag=false; break;}
                k=j-1;
            }
            else {
                if(j+L>N){flag=false; break;}
                if(j<=k){flag=false; break;}
                k=j+L-1;
            }
        }
        if(flag)cnt++;
    }
    for(int i=0;i<N;i++){
        bool flag=true;
        int k=-1;
        for(int j=1;j<N;j++){
            if(abs(a[j][i]-a[j-1][i])>1){flag=false; break;}
            if(a[j][i]==a[j-1][i])continue;
            if(a[j][i]>a[j-1][i]){
                if(j-1-k<L){flag=false; break;}
                k=j-1;
            }
            else {
                if(j+L>N){flag=false; break;}
                if(j<=k){flag=false; break;}
                k=j+L-1;
            }
        }
        if(flag)cnt++;
    }
    cout<<cnt;
    return 0;
}