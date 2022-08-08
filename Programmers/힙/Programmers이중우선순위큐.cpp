#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations) {
	vector<int> answer;
	priority_queue<int, vector<int>, less<int>> pq;
	int index = 0;
	for (int i = 0; i < operations.size(); i++) {
		string a = operations[i].substr(2);
		if (operations[i][0] == 'I') {
			pq.push(stoi(a)); index++;
		}
		else {
			if (!index)continue;
			if (a == "1") pq.pop();
			index--;
		}
	}
	if (!index) return { 0,0 };
	answer.push_back(pq.top());
	while (!pq.empty()) {
		if (index == 1)answer.push_back(pq.top());
		pq.pop(); index--;
	}
	return answer;
}
int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	vector<string> b = { "I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1" };

	vector<int> a = solution(b);
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << endl;
	return 0;
}