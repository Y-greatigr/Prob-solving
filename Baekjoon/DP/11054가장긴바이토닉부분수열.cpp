#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int main(){
    FastIO;
    int n;cin>>n;
    int a[n], dp_up[n], dp_down[n], maxi=0;
    memset(dp_up, 0, sizeof(dp_up));
    memset(dp_down, 0, sizeof(dp_down));
    dp_up[0]=1;
    dp_down[0]=1;
    for(int i=0;i<n;i++){
        cin>>a[i];
        for(int j=0;j<i;j++){
            if(a[i]>a[j] && dp_up[i]<=dp_up[j])dp_up[i]=dp_up[j]+1; // 오름차순에 대한 dp
            else if(dp_up[i]==0) dp_up[i]=1;
            if(a[i]<a[j] && dp_down[i]<=dp_down[j])dp_down[i]=dp_down[j]+1; // 내림차순에 대한 dp
            else if(dp_down[i]==0)dp_down[i]=1;
            if(a[i]<a[j] && dp_down[i]<=dp_up[j])dp_down[i]=dp_up[j]+1; // 올라가다 내려가기 시작할 때의 dp
        }
        maxi=max(dp_up[i]<dp_down[i]?dp_down[i]:dp_up[i],maxi);
    }
    cout<<maxi;
    return 0;
}