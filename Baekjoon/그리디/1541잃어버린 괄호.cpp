#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	string a, b="";
	queue<int> num;
	queue<char> oper;
	string::iterator it;
	int sum = 0;

	cin >> a;

	for (it = a.begin(); it != a.end(); ++it) {
		if ((*it) == '+' || (*it) == '-') {
			num.push(stoi(b));
			b = "";
			oper.push(*it);
		}
		else
			b += *it;
	}
	num.push(stoi(b));

	sum += num.front();
	num.pop();

	if(!num.empty()){
		while (oper.front() != '-') {
			sum += num.front();
			oper.pop();
			num.pop();

			if (num.empty())
				break;
		}

		while (!num.empty()) {
			sum -= num.front();
			num.pop();
		}
	}
	cout << sum;
	
	return 0;
}