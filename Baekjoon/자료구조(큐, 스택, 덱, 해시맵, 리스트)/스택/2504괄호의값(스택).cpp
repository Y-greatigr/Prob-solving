// #include <iostream>
// #include <string>
// #include <stack>

// using namespace std;
// stack<string> st;
// int ch = 0;
// void wow(string a, string b, string top, int d) {
// 	int ans = stoi(top);
// 	st.pop();
// 	while (!st.empty()) {
// 		top = st.top();
// 		if (top == a) {
// 			st.pop();
// 			st.push(to_string(ans * d));
// 			break;
// 		}
// 		else if (top == b) {
// 			ch = -1;
// 			return;
// 		}
// 		else {
// 			ans += stoi(top);
// 			st.pop();
// 		}
// 	}
// }
// void push(string c) {
// 	if (c == "(" || c == "[")
// 		st.push(c);
// 	else {
// 		if (st.empty()) {
// 			ch = -1;
// 			return;
// 		}
// 		string x = st.top();
// 		if (c == ")") {
// 			if (x == "(") {
// 				st.pop();
// 				st.push("2");
// 			}
// 			else if (x == "[")
// 				ch = -1;
// 			else
// 				wow("(", "[", string{ x }, 2);
// 		}
// 		else {
// 			if (x == "[") {
// 				st.pop();
// 				st.push("3");
// 			}
// 			else if (x == "(")
// 				ch = -1;
// 			else
// 				wow("[", "(", string{ x }, 3);
// 		}
// 	}
// }
// int main() {
// 	cin.tie(NULL);
// 	ios::sync_with_stdio(false);
// 	string s; cin >> s;

// 	for (int i = 0; i < s.length(); i++) {
// 		if (ch == -1) {
// 			cout << 0;
// 			return 0;
// 		}
// 		push(string{ s[i] });
// 	}

// 	int sum = 0;
// 	while (!st.empty()) {
// 		if (st.top() == "(" || st.top() == ")" || st.top() == "[" || st.top() == "]") {
// 			cout << 0;
// 			return 0;
// 		}
// 		sum += stoi(st.top());
// 		st.pop();
// 	}
// 	cout << sum;
// 	return 0;
// }

#include <bits/stdc++.h>
#define FastIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;

int main(){
    FastIO;
    vector<char> v;
    string s;
    int ans=0, tmp=1;
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]=='('){
            tmp*=2;
            v.push_back(s[i]);
        }
        else if(s[i]=='['){
            tmp*=3;
            v.push_back(s[i]);
        }
        else if(s[i]==']'){
            if(v.empty() || v.back()!='['){
                cout<<0;
                return 0;
            }
            if (s[i - 1] == '[') ans += tmp;
            v.pop_back();
            tmp /= 3;
        }
        else if(s[i]==')'){
            if(v.empty() || v.back()!='('){
                cout<<0;
                return 0;
            }
            if (s[i - 1] == '(') ans += tmp;
            v.pop_back();
            tmp /= 2;
        }
    }
    if(!v.empty())cout<<0;
    else cout<<ans;
    return 0;
}