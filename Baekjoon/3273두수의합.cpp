#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int a[2'000'001]={0,};
int main(){
    FastIO;
    int n, x, sum=0;cin>>n;
    vector<int> v;
    while(n--){
        int b;cin>>b;
        v.push_back(b);
    }
    cin>>x;
    for(auto cur:v){
        if(x>cur && (x-cur)!=cur && a[x-cur])sum++;
        a[cur]=1;
    }
    cout<<sum;
    return 0;
}