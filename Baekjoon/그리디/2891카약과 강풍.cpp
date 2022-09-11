#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

bool damage[12]={false,};
int main(){
    FastIO;
    int n,s,r;cin>>n>>s>>r;
    vector<int> v(r);
    for(int i=0;i<s;i++){
        int j;cin>>j;
        damage[j]=true;
    }

    for(int i=0;i<r;i++)cin>>v[i];
    sort(v.begin(),v.end());
    for(int i=0;i<r;i++){
        for(int j=0;j<3;j++){
            if(damage[v[i]+"102"[j]-'1']){
                damage[v[i]+"102"[j]-'1']= false;
                s--;
                break;
            }
        }
    }
    cout<<s;
    return 0;
}