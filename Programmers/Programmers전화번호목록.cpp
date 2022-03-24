#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
	sort(phone_book.begin(), phone_book.end());
	string start = phone_book[0];
	for (int i = 1; i < phone_book.size(); i++) {
		int flag = 1;
		for (int j = 0; j < start.size(); j++) {
			if (phone_book[i][j] != start[j]) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			answer = false;
			break;
		}
		start = phone_book[i];
	}
    return answer;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	vector<string> a;
	a.push_back("12");
	a.push_back("123");
	a.push_back("9767");
	a.push_back("5524421");
	cout << solution(a);
	return 0;
}