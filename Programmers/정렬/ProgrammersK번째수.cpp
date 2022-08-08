#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;
	for (int i = 0; i < commands.size(); i++) {
		int st = commands[i][0];
		int en = commands[i][1];
		int k = commands[i][2];
		vector<int> a;
		for (int j = st - 1; j < en; j++)
			a.push_back(array[j]);
		sort(a.begin(), a.end());
		answer.push_back(a[k - 1]);
	}
	return answer;
}
int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	vector<int> b(7);
	b = { 1, 5, 2, 6, 3, 7, 4 };

	vector<vector<int>> v(3);
	v = { {2, 5, 3} ,{4, 4, 1},{1, 7, 3} };

	vector<int> a = solution(b, v);
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << endl;
	return 0;
}