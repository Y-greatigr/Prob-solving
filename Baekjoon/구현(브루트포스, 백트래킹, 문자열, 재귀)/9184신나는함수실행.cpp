#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int ar[21][21][21]={0,};
int w(int a,int b, int c){
    if(a<=0 || b<=0 || c<=0)return 1;
    if(a>20 || b>20 || c>20)return w(20,20,20);
    if(ar[a][b][c])return ar[a][b][c];
    if(a<b && b<c)ar[a][b][c]=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
    else ar[a][b][c]=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
    return ar[a][b][c];
}
int main(){
    FastIO;
    int A,B,C;
    while(1){
        cin>>A>>B>>C;
        if(A==-1 && B==-1 && C==-1)break;
        cout<<"w("<<A<<", "<<B<<", "<<C<<") = "<<w(A,B,C)<<'\n';
    }
    return 0;
}