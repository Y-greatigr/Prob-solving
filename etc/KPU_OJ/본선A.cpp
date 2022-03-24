#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> output;
int d[100] = { 0, };
void translate(string input) {
	
	int a = 0;
	int b = 0;
	int c = 0;
	int e = 0;
	for (int i = 0; i < input.size(); i++) {
		string str;
		if (b == 2) {
			if (input[i] == '+') {
				str.append("(");
				str+=(input[a]);
				str.append("+");
				str += input[a + 1];
				str.append(")");
				output.push_back(str);
				a = i + 1;
				b = -1;
			}
			else if (input[i] == '-') {
				str.append("(");
				str += (input[a]);
				str.append("-");
				str += input[a + 1];
				str.append(")"); output.push_back(str);
				a = i + 1;
				b = -1;
			}
			c++;
			if (c == 1) {
				d[e++] = output.size() - 1;
			}
			else if (c == 2)
				c = 0;
		}
		else if (b == 1) {
			if (input[i] == '+') {
				str.append("(");
				str += output[output.size() - 1];
				str.append("+");
				str += input[a];
				str.append(")");
				output.push_back(str);
				a = i + 1;
				b = -1;
			}
			else if (input[i] == '-') {
				str.append("(");
				str += output[output.size() - 1];
				str.append("-");
				str += input[a];
				str.append(")"); output.push_back(str);
				a = i + 1;
				b = -1;
			}
		}
		else if (b == 0) {
			if (input[i] == '+') {
				str.append("(");
				str += output[d[e--]];
				str.append("+");
				str += output[output.size() - 1];
				str.append(")");
				output.push_back(str);
				a = i + 1;
				b = -1;
			}
			else if (input[i] == '-') {
				str.append("(");
				str += output[d[e--]];
				str.append("-");
				str += output[output.size() - 1];
				str.append(")");
				output.push_back(str);
				a = i + 1;
				b = -1;
			}
		}
		b++;
	}
}
int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string input;

	string a;
	cin >> a;

	for (int i = 0; i<a.size(); i++) {
		input.push_back(a[i]);
	}
	translate(input);
	cout << output[output.size() - 1];

	return 0;
}