#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(int n, long long left, long long right) {
	vector<int> answer;
	for (long long i = left; i <= right; i++) {
		long long row = i / n;
		long long col = i % n;
		if (row <= col)answer.push_back(col + 1);
		else answer.push_back(row + 1);
	}
	return answer;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<int> c = solution(3,2,5);
	//vector<int> c = solution(4,7,14);
	for (int i = 0; i < c.size(); i++)
		cout << c[i] << endl;
	return 0;
}