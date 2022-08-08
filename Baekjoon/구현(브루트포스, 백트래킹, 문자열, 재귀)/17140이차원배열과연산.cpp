#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
typedef pair<int,int> pii;

int ar[100][100];
vector<pii> sorting(vector<int> v){
    map<int,int> m;
    vector<pii> ans;
    for(int i=0;i<v.size();i++)m[v[i]]++;
    for(auto i:m)ans.push_back({i.second,i.first});
    sort(ans.begin(), ans.end());
    return ans;
}
int main(){
    FastIO;
    int r,c,k, i, j, cnt=0;cin>>r>>c>>k;
    for(i=0;i<3;i++)for(j=0;j<3;j++)cin>>ar[i][j];
    i--,j--;
    while(cnt<=100 && ar[r-1][c-1]!=k){
        if(i>=j){
            int maxi=0;
            for(int p=0;p<=i;p++) {
                int t;
                vector<int> v;
                for (t = 0; t <= j; t++) {
                    if (!ar[p][t])continue;
                    v.emplace_back(ar[p][t]);
                }
                vector<pii> a = sorting(v);
                for (t = 0; t < a.size() && t < 50; t++)ar[p][2*t] = a[t].second, ar[p][2*t + 1] = a[t].first;
                maxi=max(2*t-1,maxi);
                for (t = 2*a.size(); t < 100; t++)ar[p][t] = 0;
            }
            j=maxi;
        }
        else{
            int maxi=0;
            for(int p=0;p<=j;p++) {
                int t;
                vector<int> v;
                for (t = 0; t <= i; t++) {
                    if (!ar[t][p])continue;
                    v.emplace_back(ar[t][p]);
                }
                vector<pii> a = sorting(v);
                for (t = 0; t < a.size() && t < 50; t++)ar[2*t][p] = a[t].second, ar[2*t+1][p] = a[t].first;
                maxi=max(2*t-1,maxi);
                for (t = 2*a.size(); t < 100; t++)ar[t][p] = 0;
            }
            i=maxi;
        }
        cnt++;
    }
    cout<<(cnt<=100?cnt:-1);
    return 0;
}