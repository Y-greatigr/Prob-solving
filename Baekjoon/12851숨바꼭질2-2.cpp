#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int a[100001]; // 중복 횟수
int main(){
    FastIO;
    int n,k;cin>>n>>k;
    if(n==k) {cout<<"0\n1";return 0;}
    queue<int> q; // 위치
    q.push(n);
    for(int i=0;i<100001;++i)a[i]=100001;
    a[n]=0;
    int result=100'001, cnt=0;
    while(!q.empty()){
        int cur=q.front();q.pop();
        for(int i=0;i<3;i++){
			int next;
			if(i==0) next = cur-1;
			else if(i==1) next=cur+1;
			else if(i==2) next=cur*2;
            if(next<0 || next>100000)continue;
            if(a[next]<a[cur]+1)continue;
            a[next]=a[cur]+1;
            if(next==k && result>=a[next]){
                result=a[next];
                cnt++;
            }
            else if(result<a[next])break;
            q.push(next);
        }
    }
    cout<<a[k]<<'\n'<<cnt;
    return 0;
}
