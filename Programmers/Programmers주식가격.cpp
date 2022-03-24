#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer;
	for (int i = 0; i < prices.size(); i++) {
		int k = prices[i];
		int cnt = 0;
		for (int j = i + 1; j < prices.size(); j++) {
			cnt++;
			if (prices[j] < k)
				break;
		}
		answer.push_back(cnt);
	}
	return answer;
}
int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	vector<int> b(5);
	b = { 1, 2, 3, 2, 3 };

	vector<int> a = solution(b);
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << endl;
	return 0;
}