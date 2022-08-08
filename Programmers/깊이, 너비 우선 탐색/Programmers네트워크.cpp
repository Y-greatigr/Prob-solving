#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> a;
void bfs(int cur, int n, vector<vector<int>> &d) {
    queue<int> q; q.push(cur);
    vector<int> b;
    while (!q.empty()) {
        int c = q.front(); q.pop();
        for (int i = 0; i < n; i++) {
            if (d[c][i]==10 || d[c][i]==0) continue;
            d[c][i] = d[i][c] = 10;
            b.push_back(i); q.push(i);
        }
    }
    if (b.size() == 0) return;
    a.push_back(b);
}
int solution(int n, vector<vector<int>> computers) {
    for (int i = 0; i < n; i++)
        bfs(i, n, computers);
    return  a.size();
}
int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    vector<vector<int>> v = { {1, 1, 0},{1, 1, 1},{0, 1, 1} };
    cout << solution(3, v);
    return 0;
}