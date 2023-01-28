#include <bits/stdc++.h>
#define FastIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;

vector<vector<long long>> mul(vector<vector<long long>> a, vector<vector<long long>> b){
    vector<vector<long long>> ans=a;
    for(int i=0;i<8;i++)for(int j=0;j<8;j++)ans[i][j]=0;
    for(int i=0;i<8;i++)for(int j=0;j<8;j++){
        for(int k=0;k<8;k++){
            ans[i][j]+=a[i][k]*b[k][j]%1'000'000'007;
        }
        ans[i][j]%=1'000'000'007;
    }
    return ans;
}
vector<vector<long long>> cal(vector<vector<long long>> a, long long D){
    vector<vector<long long>> ans=a;
    for(int i=0;i<8;i++)for(int j=0;j<8;j++){
        if(i==j)ans[i][j]=1;
        else ans[i][j]=0;
    }
    while(D){
        if(D%2)ans=mul(ans,a);
        a=mul(a,a);
        D/=2;
    }
    return ans;
}
int main(){
    FastIO;
    long long D;cin>>D;
    vector<vector<long long>> v={{0,1,1,0,0,0,0,0},
                                 {1,0,1,1,0,0,0,0},
                                 {1,1,0,1,1,0,0,0},
                                 {0,1,1,0,1,1,0,0},
                                 {0,0,1,1,0,1,0,1},
                                 {0,0,0,1,1,0,1,0},
                                 {0,0,0,0,0,1,0,1},
                                 {0,0,0,0,1,0,1,0},};
    cout<<cal(v,D)[0][0];
    return 0;
}