/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <queue>
using namespace std;

int Answer;
struct cmp {
	bool operator()(pair<int, pair<pair<int, int>, pair<int, int>>> a, pair<int, pair<pair<int, int>, pair<int, int>>> b) {
		if (a.first == b.first) {
			return a.second.first.first + a.second.first.second < b.second.first.first + b.second.first.second;
		}
		return a.first > b.first;
	}
};
int main(int argc, char** argv)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int T, test_case;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		priority_queue<pair<int,pair<pair<int, int>, pair<int, int>>>, 
		vector<pair<int, pair<pair<int, int>, pair<int, int>>>>, cmp> v;
		int n, m; cin >> n >> m;
		int odd_num = 0;
		Answer = 0;
		for (int i = 0; i < n; i++) {
			priority_queue<int, vector<int>, greater<int>> pq;
			int a; cin >> a;
			if (a % 2 == 1)
				odd_num++;
			for (int j = 0; j < a; j++) {
				int b; cin >> b;
				pq.push(b);
			}
			int n1 = pq.top(); pq.pop();
			int n2 = pq.top(); pq.pop();
			int n3 = pq.top(); pq.pop();
			int n4 = pq.top(); pq.pop();
			int group_sum = n1 + n2 + n3 + n4;
			v.push({ group_sum, { { n1,n2 }, {n3,n4} } });
		}
		for (int i = 0; i < n - 2; i++) {
			Answer+=v.top().first;
			v.pop();
		}
		Answer += v.top().second.first.first;
		Answer += v.top().second.first.second;
		v.pop();
		Answer += v.top().second.first.first;
		Answer += v.top().second.first.second;
		v.pop();
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;
}