#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	queue<int> q;
	for (int i = 0; i < progresses.size(); i++) {
		int a = 100 - progresses[i];
		int b = (a % speeds[i]) ? a / speeds[i] + 1 : a / speeds[i];
		q.push(b);
	}
	int cnt = 1;
	int a = q.front(); q.pop();
	if (q.empty()) {
		answer.push_back(cnt);
		return answer;
	}
	while (!q.empty()) {
		int b = q.front(); q.pop();
		if (a < b) {
			answer.push_back(cnt);
			a = b; cnt = 1;
		}
		else
			cnt++;
	}
	answer.push_back(cnt);
	return answer;
}
int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	/*vector<int> b(6);
	b = { 95, 90, 99, 99, 80, 99 };

	vector<int> c(6);
	c = { 1, 1, 1, 1, 1, 1 };*/

	vector<int> b(3);
	b = { 93, 30, 55 };

	vector<int> c(3);
	c = { 1, 30, 5 };

	vector<int> k = solution(b, c);
	for (int i = 0; i < k.size(); i++)
		cout << k[i] << endl;
	return 0;
}