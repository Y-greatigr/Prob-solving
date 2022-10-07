#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int n;
string a,b;
void convert(){
    a[0]=(a[0]=='0')?'1':'0';
    a[1]=(a[1]=='0')?'1':'0';
}
void click(int ind, string& tmp){
    if(ind-1>=0)tmp[ind-1]=(tmp[ind-1]=='0')?'1':'0';
    tmp[ind]=(tmp[ind]=='0')?'1':'0';
    if(ind+1<n)tmp[ind+1]=(tmp[ind+1]=='0')?'1':'0';
}
int check(){
    string tmp=a;
    int cnt=0;
    for(int i=1;i<n;i++){
        if(tmp[i-1]!=b[i-1]){
            click(i, tmp);
            cnt++;
        }
    }
    if(tmp==b)return cnt;
    return 1'000'000'000;
}
int main(){
    FastIO;
    int mini=1'000'000'000;
    cin>>n>>a>>b;
    mini=min(mini,check());
    convert();
    mini=min(mini,check()+1);
    if(mini==1'000'000'000)cout<<-1;
    else cout<<mini;
    return 0;
}