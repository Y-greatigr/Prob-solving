#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
	int answer = 0;
	sort(rocks.begin(), rocks.end());
	int start = 0, end = distance;
	while (start <= end) {
		int cnt = 0, pre = 0, mid = (start + end) / 2;
		for (int i = 0; i < rocks.size(); i++) {
			if (rocks[i] - pre < mid) {
				cnt++; continue;
			}
			pre = rocks[i];
		}
		if (distance - pre < mid)cnt++;
		if (cnt <= n) {
			answer = mid; start = mid + 1; 
			continue;
		}
		end = mid - 1;
	}
	return answer;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int d = 25; int n = 2;
	vector<int> a = { 2, 14, 11, 21, 17 };
	cout << solution(d, a, n);
	return 0;
}