#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int InOrder[100'001];
int PostOrder[100'001];
int ind[100'001];
void PreOrder(int in_st, int in_end, int po_st, int po_end){
    if(in_st>in_end || po_st>po_end)return;
    int cur=PostOrder[po_end];
    cout<<cur<<" ";
    PreOrder(in_st, ind[cur]-1, po_st, po_st+(ind[cur]-in_st)-1);       // 왼쪽
    PreOrder(ind[cur]+1, in_end, po_st+(ind[cur]-in_st), po_end-1); // 오른쪽
}
int main(){
    FastIO;
    int n, a;cin>>n;
    for(int i=0;i<n;i++){
        cin>>InOrder[i];
        ind[InOrder[i]]=i;
    }
    for(int i=0;i<n;i++)cin>>PostOrder[i];
    PreOrder(0, n-1, 0, n-1);
    return 0;
}