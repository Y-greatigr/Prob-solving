#include <iostream>
#include <vector>
#include <string>
using namespace std;

int solution(string s) {
	int answer = 0;
	int index = 0;
	while (1) {
		if (index >= s.length())
			break;
		if (isdigit(s[index]) != 0) {
			answer = answer * 10 + s[index]-'0';
			index++;
			continue;
		}
		if (s[index] == 'z') {
			answer = answer * 10;
			index += 4;
		}
		else if (s[index] == 'o') {
			answer = answer * 10 + 1;
			index += 3;
		}
		else if (s[index] == 'e') {
			answer = answer * 10 + 8;
			index += 5;
		}
		else if (s[index] == 'n') {
			answer = answer * 10 + 9;
			index += 4;
		}
		else if (s[index] == 't') {
			if (s[index + 1] == 'w') {
				answer = answer * 10 + 2;
				index += 3;
			}
			else {
				answer = answer * 10 + 3;
				index += 5;
			}
		}
		else if (s[index] == 'f') {
			if (s[index + 1] == 'o') {
				answer = answer * 10 + 4;
				index += 4;
			}
			else {
				answer = answer * 10 + 5;
				index += 4;
			}
		}
		else if (s[index] == 's') {
			if (s[index + 1] == 'i') {
				answer = answer * 10 + 6;
				index += 3;
			}
			else {
				answer = answer * 10 + 7;
				index += 5;
			}
		}
	}
	return answer;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string a;
	cin >> a;
	cout << solution(a);
	return 0;
}