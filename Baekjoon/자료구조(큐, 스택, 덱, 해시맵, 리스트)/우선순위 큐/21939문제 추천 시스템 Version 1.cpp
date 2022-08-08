#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

struct cmp1{
    bool operator()(pair<int,int> a, pair<int,int> b){
        if(a.second==b.second){
            return a.first<b.first;
        }
        return a.second<b.second;
    }
};
struct cmp2{
    bool operator()(pair<int,int> a, pair<int,int> b){
        if(a.second==b.second){
            return a.first>b.first;
        }
        return a.second>b.second;
    }
};

map<int,int> ma;
priority_queue<pair<int,int>, vector<pair<int,int>>, cmp1> pq1;
priority_queue<pair<int,int>, vector<pair<int,int>>, cmp2> pq2;
void recommend(int x){
    if(x==1) {
        while (ma.find(pq1.top().first) == ma.end()
               || ma[pq1.top().first] != pq1.top().second) {
            pq1.pop();
        }
        cout<<pq1.top().first<<'\n';
    }
    if(x==-1){
        while(ma.find(pq2.top().first)==ma.end()
              || ma[pq2.top().first]!=pq2.top().second){
            pq2.pop();
        }
        cout<<pq2.top().first<<'\n';
    }
}

int main(){
    FastIO;
    int n,m;cin>>n;
    while(n--){
        int a,b;cin>>a>>b;
        ma[a]=b;
        pq1.push({a,b});
        pq2.push({a,b});
    }
    cin>>m;
    while(m--){
        string s;cin>>s;
        if(s[0]=='a'){
            int p,l;cin>>p>>l;
            ma[p]=l;
            pq1.push({p,l});
            pq2.push({p,l});
        }
        else if(s[0]=='r'){
            int c;cin>>c;
            recommend(c);
        }
        else if(s[0]=='s'){
            int p;cin>>p;
            ma.erase(p);
        }
    }
    return 0;
}