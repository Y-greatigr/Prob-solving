#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> v;
	int a = 665;
	string b;
	while (v.size()<N) {
		a++;
		b = to_string(a);
		if (b.find("666") != string::npos)
			v.push_back(a);
	}
	cout << v.back();
}