#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

vector<vector<long long>> mul(int n, vector<vector<long long>> a, vector<vector<long long>> b){
    vector<vector<long long>> ans=a;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++){
        ans[i][j]=0;
    }
    for(int i=0;i<n;i++)for(int j=0;j<n;j++){
        for(int k=0;k<n;k++){
            ans[i][j]+=(a[i][k]*b[k][j])%1'000;
        }
        ans[i][j]%=1'000;
    }
    return ans;
}
void divide_conquer(long long n, long long b, vector<vector<long long>> a){
    vector<vector<long long>> ans=a;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++){
        if(i==j)ans[i][j]=1;
        else ans[i][j]=0;
    }
    while(b>0){
        if(b%2)ans=mul(n, ans,a);
        a=mul(n, a,a);
        b/=2;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<'\n';
    }
}
int main(){
    FastIO;
    long long n,b;cin>>n>>b;
    vector<vector<long long>> v;
    for(int i=0;i<n;i++) {
        vector<long long> v2;
        for (int j = 0; j < n; j++) {
            long long a;cin>>a;
            v2.push_back(a);
        }
        v.push_back(v2);
    }
    divide_conquer(n, b, v);
    return 0;
}