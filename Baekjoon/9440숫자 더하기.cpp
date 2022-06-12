#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int main(){
    FastIO;
    while(true){
        int n;cin>>n;
        if(!n)break;
        vector<int> v;
        int num1=0,num2=0;
        for(int i=0;i<n;i++){
            int a;cin>>a;
            v.emplace_back(a);
        }
        sort(v.begin(),v.end());
        int i;
        for(i=0;i<n;i++){
            if(v[i])break;
        }
        num1+=v[i],num2+=v[i+1];
        bool flag=true;
        for(int j=0;j<n;j++){
            if(j==i || j==i+1)continue;
            if(flag)num1=num1*10+v[j], flag=false;
            else num2=num2*10+v[j],flag=true;
        }
        cout<<num1+num2<<'\n';
    }
    return 0;
}