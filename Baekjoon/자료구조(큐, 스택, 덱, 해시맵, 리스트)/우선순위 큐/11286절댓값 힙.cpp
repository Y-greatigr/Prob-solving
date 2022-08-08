#include <iostream>
#include <queue>
using namespace std;
class wow {
public:
	int v;
	wow(int va) :v(va){}

};
class how {
public:
	int operator()(wow t, wow u) {
		if (abs(t.v) == abs(u.v))
			return t.v > u.v;
		return abs(t.v) > abs(u.v);
	}
};
int main() {
	priority_queue< wow, vector<wow>, how > pq; //greater:ÃÖ¼ÒÈü, less:ÃÖ´ëÈü
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n;
	while (n--) {
		cin >> k;
		if (k == 0) {
			if (pq.size() == 0) {
				cout << '0' << '\n';
				continue;
			}
			cout << pq.top().v << '\n';
			pq.pop();
		}
		else {
			pq.push(k);
		}
	}
	return 0;
}