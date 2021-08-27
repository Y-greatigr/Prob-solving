#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	queue<int> q;
	int index = 0, sum = 0;
	while (1) {
		if (index == truck_weights.size()) {
			answer += bridge_length;
			break;
		}
		if (q.size() == bridge_length) {
			sum -= q.front(); q.pop();
		}
		int a = truck_weights[index]; answer++;
		if (a + sum > weight) {
			q.push(0); continue;
		}
		q.push(a);
		sum += a; index++;
	}

	return answer;
}
int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	vector<int> b(4);
	b = { 7,4,5,6 };

	//vector<int> b(4);
	//b = { 2, 1, 3, 2 };

	cout << solution(2, 10, b);
	return 0;
}