#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int main() {
    FastIO;
    int n, k, lev = 0, cnt = 0;cin >> n >> k;
	deque<int> dur(2 * n), a(2 * n); // 내구도, 로봇
	for (int i = 0; i < 2 * n; i++) cin >> dur[i];
	while (cnt < k) { // 4. 내구도가 0인 칸의 개수가 K개 이상이라면 과정을 종료
        lev++;  // 단계+1

        /**
         * @brief 1. 벨트가 각 칸 위에 있는 로봇과 함께 한 칸 회전한다.
         */
		dur.push_front(dur.back());dur.pop_back();
		a.push_front(a.back()); a.pop_back();
		a[n - 1] = 0;    

        /**
         * @brief 2. 가장 먼저 벨트에 올라간 로봇부터, 벨트가 회전하는 방향으로 한 칸 이동할 수 있다면 이동한다. 만약 이동할 수 없다면 가만히 있는다.
         * 로봇이 이동하기 위해서는 이동하려는 칸에 로봇이 없으며, 그 칸의 내구도가 1 이상 남아 있어야 한다.
         */
		priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
		for (int i = 0; i < n; i++) if (a[i]) pq.push({a[i],i});    // 가장 먼저 벨트에 올라간 로봇부터 옮기기 위해
		while (!pq.empty()) {
			int i = pq.top().second; pq.pop();
			if (!a[i + 1] && dur[i + 1]) {
				a[i + 1] = a[i], a[i] = 0, dur[i + 1]--;
				if (!dur[i + 1]) cnt++;
			}
		}
		a[n - 1] = 0;

        /**
         * @brief 3. 올리는 위치에 있는 칸의 내구도가 0이 아니면 올리는 위치에 로봇을 올린다
         */
		if (!a[0] && dur[0]) {
			a[0] = lev, dur[0]--;
			if (!dur[0]) cnt++;
		}
	}
	cout << lev;
    return 0;
}