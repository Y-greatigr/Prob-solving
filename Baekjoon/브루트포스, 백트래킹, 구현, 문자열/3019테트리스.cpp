#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int sol_1(int c, int *ar){
    int sum=0;
    for(int i=0;i<=c-4;i++){
        bool flag=true;
        for(int j=i+1;j<i+4;j++){
            if(ar[j]!=ar[j-1]){
                flag= false;
                break;
            }
        }
        if(flag)sum++;
    }
    return sum+c;
}
int sol_2(int c, int *ar){
    int sum=0;
    for(int i=0;i<=c-2;i++){
        if(ar[i]==ar[i+1])sum++;
    }
    return sum;
}
int sol_3(int c, int *ar){
    int sum=0;
    for(int i=0;i<=c-3;i++){
        if(ar[i]==ar[i+1] && ar[i+1]+1==ar[i+2])sum++;
    }
    for(int i=0;i<=c-2;i++){
        if(ar[i]-1==ar[i+1])sum++;
    }
    return sum;
}
int sol_4(int c, int *ar){
    int sum=0;
    for(int i=0;i<=c-3;i++){
        if(ar[i+2]==ar[i+1] && ar[i+1]+1==ar[i])sum++;
    }
    for(int i=0;i<=c-2;i++){
        if(ar[i]==ar[i+1]-1)sum++;
    }
    return sum;
}
int sol_5(int c, int *ar){
    int sum=0;
    for(int i=0;i<=c-3;i++){
        if(ar[i+2]==ar[i+1] && ar[i+1]==ar[i])sum++;
        if(ar[i+2]-1==ar[i+1] && ar[i+1]==ar[i]-1)sum++;
    }
    for(int i=0;i<=c-2;i++){
        if(ar[i]==ar[i+1]-1)sum++;
        if(ar[i]-1==ar[i+1])sum++;
    }
    return sum;
}
int sol_6(int c, int *ar){
    int sum=0;
    for(int i=0;i<=c-3;i++){
        if(ar[i+2]==ar[i+1] && ar[i+1]==ar[i])sum++;
        if(ar[i+2]==ar[i+1] && ar[i+1]-1==ar[i])sum++;
    }
    for(int i=0;i<=c-2;i++){
        if(ar[i]==ar[i+1])sum++;
        if(ar[i]-2==ar[i+1])sum++;
    }
    return sum;
}
int sol_7(int c, int *ar){
    int sum=0;
    for(int i=0;i<=c-3;i++){
        if(ar[i+2]==ar[i+1] && ar[i+1]==ar[i])sum++;
        if(ar[i]==ar[i+1] && ar[i+1]-1==ar[i+2])sum++;
    }
    for(int i=0;i<=c-2;i++){
        if(ar[i]==ar[i+1])sum++;
        if(ar[i]==ar[i+1]-2)sum++;
    }
    return sum;
}
int main(){
    FastIO;
    int ar[100];
    int c,p;cin>>c>>p;
    for(int i=0;i<c;i++)cin>>ar[i];
    if(p==1)cout<<sol_1(c,ar);
    else if(p==2)cout<<sol_2(c,ar);
    else if(p==3)cout<<sol_3(c,ar);
    else if(p==4)cout<<sol_4(c,ar);
    else if(p==5)cout<<sol_5(c,ar);
    else if(p==6)cout<<sol_6(c,ar);
    else if(p==7)cout<<sol_7(c,ar);
    return 0;
}