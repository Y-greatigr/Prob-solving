#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int ar[40], ar2[40];
int n,s;
vector<int> v, v2;
void accum(int *arr, vector<int> &vec, int ind, int sum, int end){
    if(ind==end){
        vec.push_back(sum);
        return;
    }
    accum(arr,vec,ind+1,sum, end);
    accum(arr,vec,ind+1,sum+arr[ind], end);
}
int main(){
    FastIO;
    long long cnt=0;
    cin>>n>>s;
    for(int i=0;i<n/2;i++)cin>>ar[i];
    for(int i=n/2;i<n;i++)cin>>ar2[i-n/2];
    accum(ar, v, 0, 0, n/2);
    accum(ar2, v2, 0, 0, n-n/2);
    sort(v2.begin(),v2.end());
    for(auto i:v){
        auto [first, last]= equal_range(v2.begin(),v2.end(), s-i);
        cnt+=last-first;
    }
    cout<<cnt-(s?0:1);
    return 0;
}