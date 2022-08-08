#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
	for (int i = 2; i <= n; i++) {
		if (n % i == 1) {
			answer = i;
			break;
		}
	}
    return answer;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cout<<solution(10);
	//cout << solution(12);

	return 0;
}