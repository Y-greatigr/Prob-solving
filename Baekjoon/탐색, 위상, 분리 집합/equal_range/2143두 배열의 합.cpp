#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int ar[1001]={0,};
int ar2[1001]={0,};
vector<int> v, v2;
void accum(int *array, vector<int> &vec, int n){
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=array[j];
            vec.push_back(sum);
        }
    }
}
int main(){
    FastIO;
    int t,n,m;cin>>t>>n;
    long long cnt=0;
    for(int i=0;i<n;i++)cin>>ar[i];
    cin>>m;
    for(int i=0;i<m;i++)cin>>ar2[i];
    accum(ar, v, n);
    accum(ar2, v2, m);
    sort(v2.begin(), v2.end());
    for(auto i:v){
        auto [first, last]= equal_range(v2.begin(), v2.end(), t-i);
        cnt+=last-first;
    }
    cout<<cnt;
    return 0;
}