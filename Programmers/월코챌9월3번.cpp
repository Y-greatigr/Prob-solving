#include <iostream>
#include <vector>

using namespace std;

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
	long long answer = -1;
	long long left = 0;
	long long right = 10000000000;
	while (left <= right) {
		long long mid = (left + right) / 2;
		long long acount = a;
		long long bcount = b;
		for (int i = 0; i < g.size(); i++) {
			long long cnt = mid / (t[i] * 2) + 1;
			/**/
		}
		if (!acount && !bcount) {
			right = mid - 1;
			answer = mid;
			continue;
		}
		left = mid + 1;
	}
	return answer;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	//vector<int> g = { 70,70,0 };
	vector<int> g = { 100 };

	//vector<int> s = { 1,2,3,4,6,7,8,0 };
	vector<int> s = { 0,0,500 };

	//vector<int> w = { 1,2,3,4,6,7,8,0 };
	vector<int> w = { 100,100,2 };

	//vector<int> t = { 1,2,3,4,6,7,8,0 };
	vector<int> t = { 4,8,1 };

	cout << solution(10, 10, g, s, w, t);
	//cout << solution(90, 500, g, s, w, t);
	return 0;
}