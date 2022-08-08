#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 1;
	priority_queue<int, vector<int>, less<int>> pq;
	for (int i = 0; i < priorities.size(); i++)
		pq.push(priorities[i]);

	int index = 0;
	int imp = pq.top(); pq.pop();
	while (!pq.empty()) {
		if (imp != priorities[index]) {
			if (index == (priorities.size() - 1)) index = 0;
			else index++;
			continue;
		}
		if (location == index) return answer;
		if (location > index) location--;
		priorities.erase(priorities.begin() + index, priorities.begin() + index + 1);
		if (index == priorities.size()) index = 0;
		answer++;
		imp = pq.top(); pq.pop();
	}
	return answer;
}
int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	vector<int> b(6);
	b = { 1, 1, 9, 1, 1, 1 };

	//vector<int> b(4);
	//b = { 2, 1, 3, 2 };

	cout<< solution(b, 0);
	return 0;
}