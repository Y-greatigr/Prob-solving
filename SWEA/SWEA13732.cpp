#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int main(){
    FastIO;
    int T;cin>>T;
    for(int i=1;i<=T;i++){
        int n;cin>>n;
        char ar[n][n];
        bool flag=true, flag2=true;
        int init_r,init_c,fin_r,fin_c;
        for(int j=0;j<n;j++)for(int k=0;k<n;k++){
            cin>>ar[j][k];
            if(ar[j][k]=='#' && flag){
                flag=false;
                init_r=j,init_c=k;
            }
            if(ar[j][k]=='#' && !flag){
                fin_r=j,fin_c=k;
            }
        }
        if(fin_r-init_r!=fin_c-init_c){
            cout<<'#'<<i<<" "<<"no"<<'\n';
            continue;
        }
        for(int j=0;j<n;j++)for(int k=0;k<n;k++){
            if(init_r<=j && init_c<=k && j<=fin_r && k<=fin_c){
                if(ar[j][k]!='#'){
                    flag2=false;
                    break;
                }
            }
            else{
                if(ar[j][k]=='#'){
                    flag2=false;
                    break;
                }
            }
        }
        cout<<'#'<<i<<" "<<(flag2?"yes":"no")<<'\n';
    }
    return 0;
}