#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

pair<double,double> ar[101];
int parent[101];
vector<tuple<int,int,double>> v;
int Find(int cur){
    if(parent[cur]==cur)return cur;
    return parent[cur]=Find(parent[cur]);
}
void Union(int a, int b){
    a= Find(a);
    b= Find(b);
    if(a==b)return;
    if(a<b)parent[b]=a;
    else parent[a]=b;
}
bool cmp(tuple<int,int,double> a, tuple<int,int,double> b){
    return get<2>(a)<get<2>(b);
}
int main(){
    FastIO;
    int n, cnt=0;cin>>n;
    double sum=0;
    for(int i=1;i<=n;i++){
        parent[i]=i;
        double a,b;cin>>a>>b;
        ar[i]={a,b};
        for(int j=1;j<i;j++){
            auto [c,d]=ar[j];
            v.push_back({j,i,sqrt(pow(c-a,2)+pow(d-b,2))});
        }
    }
    sort(v.begin(), v.end(), cmp);
    for(auto i:v){
        auto [a,b,c]=i;
        a=Find(a);
        b=Find(b);
        if(a==b)continue;
        Union(a,b);
        sum+=c;
        cnt++;
        if(cnt==n-1)break;
    }
    cout<<fixed;
    cout.precision(2);
    cout<<sum;
    return 0;
}