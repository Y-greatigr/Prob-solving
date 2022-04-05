#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

char a[3072][6144];
int n;

void fill_it(int row, int col){
    a[row][col]='*';
    a[row+1][col-1]='*';
    a[row+1][col+1]='*';
    a[row+2][col-2]='*';
    a[row+2][col-1]='*';
    a[row+2][col-0]='*';
    a[row+2][col+1]='*';
    a[row+2][col+2]='*';
}
void divide_and_conquer(int len, int row, int col){
    if(len==3){
        fill_it(row, col);
        return;
    }
    divide_and_conquer(len/2, row, col);
    divide_and_conquer(len/2, row+len/2, col-len/2);
    divide_and_conquer(len/2, row+len/2, col+len/2);
}
int main(){
    FastIO;
    cin>>n;
    fill(&a[0][0], &a[n-1][2*n-1] ,' ');
    divide_and_conquer(n, 0, n-1);
    for(int i=0;i<n;i++){
        for(int j=0;j<2*n-1;j++){
            cout<<a[i][j];
        }
        cout<<'\n';
    }
    return 0;
}
