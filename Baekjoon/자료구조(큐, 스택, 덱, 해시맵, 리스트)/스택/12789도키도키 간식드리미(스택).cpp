#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int main(){
    FastIO;
    int n, ind=1;cin>>n;
    vector<int> v;
    while(n--){
        int a;cin>>a;
        if(a==ind){
            ind++;
            while(!v.empty() && ind==v.back()){
                v.pop_back();
                ind++;
            }
        }
        else{
            v.push_back(a);
        }
    }
    if(v.empty())cout<<"Nice";
    else cout<<"Sad";
    return 0;
}