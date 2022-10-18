#include<bits/stdc++.h>


using namespace std;

vector<tuple<int,int,int>> proposal;
vector<tuple<int,int,int>> scen;
int ar[100'000]={0,};

bool cmp(tuple<int,int,int> a, tuple<int,int,int> b){
    return get<1>(a)<get<1>(b);
}
int main(int argc, char** argv)
{
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int ai;cin>>ai;
        for(int j=0;j<ai;j++){
            int s,p;cin>>s>>p;
            proposal.push_back({s,p, i});
        }
    }
    int m;cin>>m;
    for(int i=0;i<m;i++){
        int q;cin>>q;
        scen.push_back({q,i,0});
    }
    sort(proposal.begin(), proposal.end());
    sort(scen.begin(), scen.end());

    int price=0;
    int ind=0;
    for(int i=0;i<proposal.size();i++){
        auto cur=proposal[i];
        if(get<1>(cur) > ar[get<2>(cur)]){
            price+= (get<1>(cur)-ar[get<2>(cur)]);
            ar[get<2>(cur)] = get<1>(cur);
        }
        while(ind<scen.size() && get<0>(scen[ind])<=price){
            get<2>(scen[ind])+=get<0>(cur);
            ind++;
        }
    }
    sort(scen.begin(), scen.end(), cmp);
    for(auto i:scen){
        if(get<2>(i))cout<<get<2>(i)<<" ";
        else cout<<-1<<" ";
    }
    return 0;
}