#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int N,M,H, mini=4;
int A[30][10]={0,};

bool check(){
    for(int i=0;i<N;i++){
        int k=i;
        for(int j=0;j<H;j++){
            if(A[j][k])k++;
            else if(k>0 && A[j][k-1])k--;            
        }
        if(i!=k) return false;
    }
    return true;
}
void dfs(int cur, int cnt){
    if(cnt>3)return;
    if(check()){mini=min(mini,cnt); return;}
    for(int i=cur;i<N-1;i++){
        for(int j=0;j<H;j++){
            if(A[j][i] || (i>0 && A[j][i-1]) || (i<N-2 && A[j][i+1]))continue;
            A[j][i]=1;
            dfs(i, cnt+1);
            A[j][i]=0;
            while((i>0 && !A[j][i-1]) && (i<N-2 && !A[j][i+1])) j++;    // 시간 줄이기
        }
    }
}
int main(){
    FastIO;
    cin>>N>>M>>H;
    for(int i=0;i<M;i++){
        int a,b;cin>>a>>b;
        A[a-1][b-1]=1;
    }
    dfs(0, 0);
    if(mini==4)mini=-1;
    cout<<mini;
    return 0;
}