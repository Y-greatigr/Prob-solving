#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int main(){
    FastIO;
    int n;cin>>n;
    set<int> s;
    for(int i=0;i<=n;i++){
        for(int j=0;i+j<=n;j++){
            for(int k=0;i+j+k<=n;k++){
                int sum = 1*i + 5*j + 10*k + (n-i-j-k)*50;
                s.insert(sum);
            }
        }
    }
    cout<<s.size();
    return 0;
}