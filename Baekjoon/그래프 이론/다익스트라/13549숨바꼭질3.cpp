#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int a[100001]; // 중복 횟수
int main(){
    FastIO;
    int n,k;cin>>n>>k;
    if(n==k) {cout<<"0";return 0;}

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,n});
    for(int i=0;i<100001;++i)a[i]=100001;
    a[n]=0;
    int result=100'001;
    while(!pq.empty()){
        auto cur=pq.top();pq.pop();
        for(int i=0;i<3;i++){
            int t=cur.first+1;
			int next;
			if(i==0) {
                t-=1;
                next=cur.second*2;
            }
			else if(i==1) next=cur.second+1;
			else if(i==2) next = cur.second-1;
            if(next<0 || next>100000)continue;
            if(a[next]<a[cur.second]+1)continue;
            a[next]=t;
            if(next==k)break;
            pq.push({t, next});
        }
    }
    cout<<a[k];
    return 0;
}