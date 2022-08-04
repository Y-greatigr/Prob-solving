#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string kia[101][101];
string bo(string a, string b) {
	int sum = 0;
	string result = "";
	while (!a.empty() || !b.empty() || sum) {
		if (!a.empty()) {
			sum += a.back() - '0';
			a.pop_back();
		}
		if (!b.empty()) {
			sum += b.back() - '0';
			b.pop_back();
		}
		result.push_back((sum % 10) + '0');
		sum /= 10;
	}
	reverse(result.begin(), result.end());
	return result;
}
string wow(int n, int m) {
	if (n == m || m == 0)
		return "1";
	string& result = kia[n][m]; //참조형으로 하지 않으면 시간 초과 (되긴 함)
	if (result != "")
		return result;
	result = bo(wow(n - 1, m - 1), wow(n - 1, m));
	return result;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m; cin >> n >> m;
	cout << wow(n, m);

	return 0;
}