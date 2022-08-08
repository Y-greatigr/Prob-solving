#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
bitset<(1<<25)> bit;
int main(){
    FastIO;
    int n;
    while(cin>>n){
        if(!bit[n]){
            cout<<n<<" ";
            bit[n]=1;
        }
    }
    return 0;
}

/**
 * 위는 비트셋으로
 * 아래는 배열의 비트마스킹으로
 */
//#include <bits/stdc++.h>
//#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
//using namespace std;
//int bit[(1<<20)];
//int main(){
//    FastIO;
//    int n;
//    while(cin>>n){
//        int x=n/32, y=n%32;
//        if(!(bit[x]&(1<<y))){
//            cout<<n<<" ";
//            bit[x] = bit[x] | (1<<y);
//        }
//    }
//    return 0;
//}