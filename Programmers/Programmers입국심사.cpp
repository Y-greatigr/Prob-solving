#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
	long long answer = 0;
	sort(times.begin(), times.end());
	long long start = 0, end = (long long) times[times.size() - 1] * n;
	while (start <= end) {
		long long mid = (start + end) / 2;
		long long cnt = 0;
		for (int i = 0; i < times.size(); i++)
			cnt += mid / times[i];
		if (cnt < n) {
			start = mid + 1; continue;
		}
		if (mid <= end)
			answer = mid;
		end = mid - 1;
	}
	return answer;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	vector<int> a = { 7,10 };
	cout << solution(6, a);
	return 0;
}