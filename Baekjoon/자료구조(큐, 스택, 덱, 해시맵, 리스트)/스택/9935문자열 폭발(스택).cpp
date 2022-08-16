#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int main(){
    FastIO;
    string a,b, s="";cin>>a>>b;
    for(int i=0;i<a.length();i++){
        if(a[i]!=b.back()){
            s+=a[i];
            continue;
        }
        bool flag=true;
        string tmp=string(1,a[i]);
        for(int j=b.length()-2;j>=0;j--){
            if(!s.empty() && b[j]==s.back()){
                tmp=b[j]+tmp;
                s.pop_back();
            }
            else{
                flag=false;
                break;
            }
        }
        if(!flag) s+=tmp;
    }
    if(s.empty())cout<<"FRULA";
    else cout<<s;
    return 0;
}