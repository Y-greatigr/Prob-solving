#include <iostream>
#include <string>
#include <queue>
using namespace std;
int ar[1000][1000];
int b[1000][1000][11];
int x[4] = { -1,0,0,1 };
int y[4] = { 0,1,-1,0 };
int M;
int N;
int K;
class d {
public:
    int m, n, k;
};
int bfs() {
    queue<d> qu;
    qu.push({ 0,0,0 });
    ar[0][0] = 1;
    b[0][0][0] = 1;

    while (!qu.empty()) {
        int m = qu.front().m;
        int n = qu.front().n;
        int k = qu.front().k;
        if (m == M - 1 && n == N - 1)
            return b[m][n][k];
        qu.pop();
        for (int t = 0; t < 4; t++) {
            int rx = m + x[t];
            int cy = n + y[t];
            int pk = k + 1;
            if (rx < 0 || rx >= M || cy < 0 || cy >= N)
                continue;
            if (b[rx][cy][k] != 0)
                continue;
            if (ar[rx][cy] == 1 && k < K) {
                qu.push({rx, cy, pk});
                b[rx][cy][pk] = b[m][n][k] + 1;
            }
            else if (ar[rx][cy] == 0) {
                qu.push({ rx, cy, k });
                b[rx][cy][k] = b[m][n][k] + 1;
            }
        }
    }
    return -1;
}
int main() {

    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> M >> N >> K;
    string a;
    for (int i = 0; i < M; i++) {
        cin >> a;
        for (int j = 0; j < N; j++) {
            ar[i][j] = a[j] - '0';
        }
    }
    cout << bfs();

    return 0;
}