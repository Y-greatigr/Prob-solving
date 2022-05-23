#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int main(){
    FastIO;
    int T;cin>>T;
    while(T--){
        int x1,y1,x2,y2,n, sum=0;cin>>x1>>y1>>x2>>y2>>n;
        while(n--){
            int cx,cy,r;cin>>cx>>cy>>r;
            if((pow(x1-cx,2)+pow(y1-cy,2)<pow(r,2) && pow(x2-cx,2)+pow(y2-cy,2)>pow(r,2))
            || (pow(x1-cx,2)+pow(y1-cy,2)>pow(r,2) && pow(x2-cx,2)+pow(y2-cy,2)<pow(r,2)))sum++;
        }
        cout<<sum<<'\n';
    }
    return 0;
}