#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
	int answer = 0;
	int m = 7;
	int term2 = 10;
	for (int i = 2; i < n; i++) {
		m += term2;
		term2 += 4;
	}
	answer = m * 3 - 6;
	return answer;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cout << solution(1000);
	//cout << solution(12);

	return 0;
}