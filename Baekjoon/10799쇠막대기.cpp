#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string s; cin >> s;
	int n = 0;
	stack<char> st;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') {
			st.push(s[i]);
		}
		else {
			if (s[i - 1] == ')') {
				n += 1;
				st.pop();
			}
			else {
				st.pop();
				n += st.size();
			}
		}
	}
	cout << n;
	return 0;
}