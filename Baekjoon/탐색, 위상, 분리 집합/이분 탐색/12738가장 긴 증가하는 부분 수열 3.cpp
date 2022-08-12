//#include <bits/stdc++.h>
//#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
//using namespace std;
//
//int ar[1'000'000];
//int main(){
//    FastIO;
//    int n, sum=0;cin>>n;
//    for(int i=0;i<n;i++){
//        int a;cin>>a;
//        auto cur= lower_bound(ar, ar+sum,a);
//        *cur=a;
//        if(ar+sum==cur)sum++;
//    }
//    cout<<sum;
//    return 0;
//}

#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int ar[1'000'000];
int main(){
    FastIO;
    int n, sum=1;cin>>n;
    cin>>ar[0];
    for(int i=1;i<n;i++){
        int a, left=0, right=sum;cin>>a;
        while(left<right){
            int mid=(left+right)/2;
            if(ar[mid]<a)left=mid+1;
            else right=mid;
        }
        if(right==sum)sum++;
        ar[right]=a;
    }
    cout<<sum;
    return 0;
}