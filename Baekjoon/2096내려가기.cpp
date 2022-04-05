#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int main(){
    FastIO;
    int n, maxi[3], mini[3];
    cin>>n>>maxi[0]>>maxi[1]>>maxi[2];
    for(int i=0;i<3;i++)mini[i]=maxi[i];
    for(int i=1;i<n;i++){
        int a,b,c;cin>>a>>b>>c;
        
        int d=maxi[0],e=maxi[1],f=maxi[2];
        maxi[0]=max(d+a,e+a);
        maxi[1]=max(max(d+b,e+b),f+b);
        maxi[2]=max(e+c,f+c);
        
        d=mini[0],e=mini[1],f=mini[2];
        mini[0]=min(d+a,e+a);
        mini[1]=min(min(d+b,e+b),f+b);
        mini[2]=min(e+c,f+c);
    }
    cout<<max(max(maxi[0],maxi[1]),maxi[2])<<" "<<min(min(mini[0],mini[1]),mini[2]);
    return 0;
}
