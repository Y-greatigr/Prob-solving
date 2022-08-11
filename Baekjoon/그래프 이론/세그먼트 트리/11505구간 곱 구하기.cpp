#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

long long ar[1'000'001];
long long segTree[4'000'000];
long long init_segmenTree(int start, int end, int cur){
    if(start==end) return segTree[cur]=ar[start];
    return segTree[cur]=(init_segmenTree(start, (start+end)/2, cur*2)
            * init_segmenTree((start+end)/2+1, end, cur*2+1)) % 1'000'000'007;
}
long long mul(int start, int end, int cur, int left, int right){
    if(left>end || right<start) return 1;
    if(left<=start && right>=end) return segTree[cur];
    return (mul(start, (start+end)/2, cur*2, left, right)
            * mul((start+end)/2+1, end, cur*2+1, left, right)) % 1'000'000'007;
}
long long change(int start, int end, int cur, int ind, long long c){
    if(ind<start || ind>end)return segTree[cur];
    if(start==end)return segTree[cur]=c;
    return segTree[cur]=(change(start, (start+end)/2, cur*2, ind, c)
            * change((start+end)/2+1, end, cur*2+1, ind, c)) % 1'000'000'007;
}
int main(){
    FastIO;
    int N,M,K;cin>>N>>M>>K;
    for(int i=1;i<=N;i++)cin>>ar[i];
    init_segmenTree(1, N, 1);
    for(int i=0;i<M+K;i++){
        long long a,b,c;cin>>a>>b>>c;
        if(--a){    // a가 2인 경우, 출력
            cout<<mul(1,N,1,b,c)<<'\n';
        }
        else{       // a가 1인 경우, 교환
            ar[b]=c;
            change(1,N,1, b, c);
        }
    }
    return 0;
}