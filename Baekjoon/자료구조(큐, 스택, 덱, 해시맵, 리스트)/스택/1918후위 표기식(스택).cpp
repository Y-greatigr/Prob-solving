#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int main(){
    FastIO;
    string s, ss="";cin>>s;
    stack<char> st;
    for(int i=0;i<s.length();i++){
        if(s[i]>='A' && s[i]<='Z')ss+=s[i];
        else if(s[i]=='*' || s[i]=='/'){
            while(!st.empty() && (st.top()=='*'||st.top()=='/')){
                ss+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        else if(s[i]=='+' || s[i]=='-'){
            while(!st.empty() && st.top()!='('){
                ss+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
                ss+=st.top();
                st.pop();
            }
            st.pop();
        }
    }
    while(!st.empty()){
        ss+=st.top();
        st.pop();
    }
    cout<<ss;
    return 0;
}