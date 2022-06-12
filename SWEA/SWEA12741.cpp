#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

vector<string> v;
int main(){
    FastIO;
    int t;cin>>t;
    for(int i=1;i<=t;i++){
        int a,b,c,d, time=0;cin>>a>>b>>c>>d;
        if(a<=c){
            if(b<=d){
                if(c>=b)time=0;
                else time=b-c;
            }
            else
                time=d-c;
        }
        else{
            if(b>=d){
                if(a>=d)time=0;
                else time=d-a;
            }
            else
                time=b-a;
        }
        v.push_back("#"+ to_string(i)+" "+ to_string(time));
    }
    for(int i=0;i<t;i++){
        cout<<v[i]<<'\n';
    }
    return 0;
}