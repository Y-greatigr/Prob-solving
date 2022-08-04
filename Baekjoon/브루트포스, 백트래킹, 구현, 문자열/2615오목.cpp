#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int main(){
    FastIO;
    int ar[20][20];
    for(int i=1;i<20;i++)for(int j=1;j<20;j++)cin>>ar[i][j];
    for(int i=1;i<20;i++)for(int j=1;j<20;j++){
        if(!ar[i][j])continue;
        int sum=0;
        //오른쪽
        for(int k=j+1;k<j+5 && k<20;k++){
            if(ar[i][k]==ar[i][j])sum++;
        }
        if(sum==4 && (j+5>=20 || (j+5<20 && ar[i][j+5]!=ar[i][j]))
            && (j-1<=0 || (j-1>0 && ar[i][j]!=ar[i][j-1]))){
            cout<<ar[i][j]<<'\n';
            cout<<i<<" "<<j;
            return 0;
        }
        //아래쪽
        sum=0;
        for(int k=i+1;k<i+5 && k<20;k++){
            if(ar[k][j]==ar[i][j])sum++;
        }
        if(sum==4 && (i+5>=20 || (i+5<20 && ar[i+5][j]!=ar[i][j]))
            && (i-1<=0 || (i-1>0 && ar[i][j]!=ar[i-1][j]))){
            cout<<ar[i][j]<<'\n';
            cout<<i<<" "<<j;
            return 0;
        }

        //오른 아래
        sum=0;
        for(int k=i+1, p=j+1;k<i+5 && k<20 && p<j+5 && p<20;k++,p++){
            if(ar[k][p]==ar[i][j])sum++;
        }
        if(sum==4 && (i+5>=20 || j+5>=20
        || (i+5<20 && j+5<20 && ar[i+5][j+5]!=ar[i][j]))
        && (i-1<=0 || j-1<=0
            || (i-1>0 && j-1>0 && ar[i-1][j-1]!=ar[i][j]))){
            cout<<ar[i][j]<<'\n';
            cout<<i<<" "<<j;
            return 0;
        }

        //오른 위
        sum=0;
        for(int k=i-1, p=j+1;k>i-5 && k>0 && p<j+5 && p<20;k--,p++){
            if(ar[k][p]==ar[i][j])sum++;
        }
        if(sum==4 && (i-5<=0 || j+5>=20
          || (i-5>0 && j+5<20 && ar[i-5][j+5]!=ar[i][j]))
         && (i+1>20 || j-1<=0
             || (i+1<20 && j-1>0 && ar[i+1][j-1]!=ar[i][j]))){
            cout<<ar[i][j]<<'\n';
            cout<<i<<" "<<j;
            return 0;
        }
    }
    cout<<0;
    return 0;
}