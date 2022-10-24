#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int main(){
    FastIO;
    string a[50], answer="";
    int n;cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<a[0].length();i++){
        bool flag=true;
        for(int j=0;j<n-1;j++){
            if(a[j][i]!=a[j+1][i]){
                flag=false;
                break;
            }
        }
        if(flag)answer+=a[0][i];
        else answer+="?";
    }
    cout<<answer;
    return 0;
}