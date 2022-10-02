#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int main(){
    FastIO;
    string s;
    regex re("problem",  regex::icase);
    while(getline(cin, s)){
        if(regex_search(s,re))cout<<"yes\n";
        else cout<<"no\n";
    }
    return 0;
}