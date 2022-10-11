#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, maxi=0;
int ar[20][20];
vector<vector<vector<int > > > v;

// 복사
void copy(){
    vector<vector<int > > tmp(n);
    for(int i=0;i<n;i++){
        vector<int> tmp2(n);
        for(int j=0;j<n;j++)tmp2[j]=ar[i][j];
        tmp[i]=tmp2;
    }
    v.push_back(tmp);
}

// 오른쪽으로 몰아넣기
void right_once(int i){
    int ind=n-1;
    for(int j=n-1;j>=0;j--){
        if(ar[i][j] && j!=ind){
            ar[i][ind--]=ar[i][j];
            ar[i][j]=0;
        }
        else if(ar[i][j])ind--;
    }
}

// 위쪽으로 몰아넣기
void up_once(int j){
    int ind=0;
    for(int i=0;i<n;i++){
        if(ar[i][j] && i!=ind){
            ar[ind++][j]=ar[i][j];
            ar[i][j]=0;
        }
        else if(ar[i][j])ind++;
    }
}

// 왼쪽으로 몰아넣기
void left_once(int i){
    int ind=0;
    for(int j=0;j<n;j++){
        if(ar[i][j] && j!=ind){
            ar[i][ind++]=ar[i][j];
            ar[i][j]=0;
        }
        else if(ar[i][j])ind++;
    }
}

// 아래쪽으로 몰아넣기
void down_once(int j){
    int ind=n-1;
    for(int i=n-1;i>=0;i--){
        if(ar[i][j] && i!=ind){
            ar[ind--][j]=ar[i][j];
            ar[i][j]=0;
        }
        else if(ar[i][j])ind--;
    }
}

// 오른쪽 이동
void move_right(){
    for(int i=0;i<n;i++){
        right_once(i);
        for(int j=n-1;j>0;j--){
            if(ar[i][j] && ar[i][j]==ar[i][j-1]){
                ar[i][j]*=2;
                ar[i][j-1]=0;
                j--;
            }
        }
        right_once(i);
    }
}

// 위쪽 이동
void move_up(){
    for(int j=0;j<n;j++){
        up_once(j);
        for(int i=0;i<n-1;i++){
            if(ar[i][j] && ar[i][j]==ar[i+1][j]){
                ar[i][j]*=2;
                ar[i+1][j]=0;
                i++;
            }
        }
        up_once(j);
    }
}

// 왼쪽 이동
void move_left(){
    for(int i=0;i<n;i++){
        left_once(i);
        for(int j=0;j<n-1;j++){
            if(ar[i][j] && ar[i][j]==ar[i][j+1]){
                ar[i][j]*=2;
                ar[i][j+1]=0;
                j++;
            }
        }
        left_once(i);
    }
}

// 아래쪽 이동
void move_down(){
    for(int j=0;j<n;j++){
        down_once(j);
        for(int i=n-1;i>0;i--){
            if(ar[i][j] && ar[i][j]==ar[i-1][j]){
                ar[i][j]*=2;
                ar[i-1][j]=0;
                i++;
            }
        }
        down_once(j);
    }
}

// 복사하고 방향 설정
void moving(int k){
    copy();
    if(k==0)move_right();
    else if(k==1)move_up();
    else if(k==2)move_left();
    else if(k==3)move_down();
}

// 움직이기 전의 값으로 복원
void unmoving(){
    vector<vector<int > > tmp=v.back();v.pop_back();
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)ar[i][j]=tmp[i][j];
}
void dfs(int cnt){
    if(cnt==5){
        for(int i=0;i<n;i++)for(int j=0;j<n;j++)maxi=max(maxi,ar[i][j]);
        return;
    }
    for(int k=0;k<4;k++){
        moving(k);
        dfs(cnt+1);
        unmoving();
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++){
        cin>>ar[i][j];
        maxi=max(maxi,ar[i][j]);
    }
    dfs(0);
    cout<<maxi;
    return 0;
}