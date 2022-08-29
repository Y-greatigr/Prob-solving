#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

vector<long long> v;
int main(){
    FastIO;
    int n;cin>>n;
    long long a,b,c, ans=3'000'000'001;
    for(int i=0;i<n;i++){cin>>a;v.push_back(a);}
    sort(v.begin(),v.end());
    for(int left=0;left<n-2 && ans;left++){
        long long mid=left+1, right=n-1;
        while (mid<right){
            long long sum=v[left]+v[mid]+v[right];
            if(abs(sum)<abs(ans)){
                a=v[left],b=v[mid],c=v[right];
                ans=sum;
            }
            if(!sum)break;
            if(sum>0)right--;
            else mid++;
        }
    }
    cout<<a<<" "<<b<<" "<<c;
    return 0;
}