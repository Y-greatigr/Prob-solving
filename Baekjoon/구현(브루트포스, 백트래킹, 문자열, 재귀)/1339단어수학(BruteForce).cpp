#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

vector<string> s;
map<char,int> m;
vector<char> char_set;
int maxi=0;

void dfs(int cur, int k){
    if(cur==char_set.size()){
        int sum=0;
        for(int i=0;i<s.size();i++){
            int num=0;
            for(int j=0;j<s[i].length();j++)num=num*10+m[s[i][j]];
            sum+=num;
        }
        maxi=max(sum, maxi);
        return;
    }
    for(int i=0;i<char_set.size();i++){
        if(m[char_set[i]]!=-1)continue;
        m[char_set[i]]=k;
        dfs(cur+1, k-1);
        m[char_set[i]]=-1;
    }
}
int main(){
    FastIO;
    int n;cin>>n;
    for(int i=0;i<26;i++)m[(char)('A'+i)]=-2;
    for(int i=0;i<n;i++){
        string a;cin>>a;
        s.emplace_back(a);
        for(int j=0;j<a.length();j++) {
            if(m[a[j]]==-2){
                m[a[j]]=-1;
                char_set.emplace_back(a[j]);
            }
        }
    }
    for(int i=0;i<char_set.size();i++){
        m[char_set[i]]=9;
        dfs(1, 8);
        m[char_set[i]]=-1;
    }
    cout<<maxi;
    return 0;
}