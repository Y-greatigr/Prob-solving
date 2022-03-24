#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int R, C;
char ar[11][11];
int visited[11][11];
int xx[4] = { 0,0,-1,1 };
int yy[4] = { 1,-1,0,0 };
void input() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++)
			cin >> ar[i][j];
	}
	memset(visited, 0, sizeof(visited));
}
void solution() {
	int fig[5];
	memset(fig, 0, sizeof(fig));
	int ans = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (ar[i][j] == '.')continue;
			char c = ar[i][j];
			if (visited[i][j])continue;
			int flag1 = 1;
			
			for (int k = 1; k <= 3; k++) {
				int col = j + k;
				if (col >= C) { flag1 = 0; break; }
				if (ar[i][col] != c)flag1 = 0;
			}
			if (flag1) {
 				fig[1]++;
				j = j + 2;
				continue;
			}

			for (int k = 1; k <= 3; k++) {
				int row= i+ k;
				if (row>=R) { flag1 = 0; break; }
				if (ar[row][j] != c)flag1 = 0;
			}
			if (flag1) {
				fig[1]++;
				continue;
			}

			int flag2 = 1;
			if (j + 1 >= C || ar[i][j + 1] != c)flag2 = 0;
			else if (i+1>=R || j >= C || ar[i+1][j] != c)flag2 = 0;
			else if (i+1>=R ||j + 1 >= C || ar[i+1][j + 1] != c)flag2 = 0;
			if (flag2) {
				fig[0]++;
				visited[i][j] = 1;
				visited[i][j + 1] = 1;
				visited[i+1][j + 1] = 1;
				visited[i+1][j + 0] = 1;
				continue;
			}

			int flag3 = 1;
			if (j + 1 >= C || ar[i][j + 1] != c)flag3 = 0;
			else if (i -1 <0 || j+1 >= C || ar[i -1][j+1] != c)flag3 = 0;
			else if (i -1<0 || j + 2 >= C || ar[i-1][j + 2] != c)flag3 = 0;
			if (flag3) {
				fig[2]++;
				visited[i][j] = 1;
				visited[i][j + 1] = 1;
				visited[i-1][j + 2] = 1;
				visited[i-1][j + 1] = 1;
				continue;
			}

			flag3 = 1;
			if (i+1 >=R || ar[i+1][j] != c)flag3 = 0;
			else if (i+1 >=R || j + 1 >= C || ar[i+ 1][j + 1] != c)flag3 = 0;
			else if (i +2>=R || j + 1 >= C || ar[i+2][j + 1] != c)flag3 = 0;
			if (flag3) {
				fig[2]++;
				continue;
			}

			int flag4 = 1;
			if (j + 1 >= C || ar[i][j + 1] != c)
				flag4 = 0;
			else if (i + 1 >=R || j + 1 >= C || ar[i + 1][j + 1] != c)
				flag4 = 0;
			else if (i + 1 >=R || j + 2 >= C || ar[i + 1][j + 2] != c)
				flag4 = 0;
			if (flag4) {
				fig[3]++;
				visited[i][j] = 1;
				visited[i][j + 1] = 1;
				visited[i + 1][j + 2] = 1;
				visited[i + 1][j + 1] = 1;
				continue;
			}

			flag4 = 1;
			if (i-1<0 || ar[i-1][j] != c)
				flag4 = 0;
			else if (i - 1 <0 || j + 1 >= C || ar[i - 1][j + 1] != c)
				flag4 = 0;
			else if (i -2 <0 || j + 1 >= C || ar[i -2][j + 1] != c)
				flag4 = 0;
			if (flag4) {
				fig[3]++;
				continue;
			}

			int flag5 = 1;
			if (j + 1 >= C || ar[i][j + 1] != c)flag5 = 0;
			else if (j + 2 >= C || ar[i][j + 2] != c)flag5 = 0;
			else if (i -1 <0 || j + 1 >= C || ar[i - 1][j + 1] != c)flag5 = 0;
			if (flag5) {
				fig[4]++;
				visited[i][j] = 1;
				visited[i][j + 1] = 1;
				visited[i][j + 2] = 1;
				visited[i - 1][j + 1] = 1;
				continue;
			}

			flag5 = 1;
			if (j + 1 >= C || ar[i][j + 1] != c)flag5 = 0;
			else if (i-1<0|| j + 1 >= C || ar[i-1][j + 1] != c)flag5 = 0;
			else if (i+1>=R || j + 1 >= C || ar[i +1][j + 1] != c)flag5 = 0;
			if (flag5) {
				fig[4]++;
				continue;
			}

			flag5 = 1;
			if (i + 1 >= R || ar[i+1][j] != c)flag5 = 0;
			else if (i +2>=R || ar[i+2][j] != c)flag5 = 0;
			else if (i + 1 >= R || j + 1 >= C || ar[i + 1][j + 1] != c)flag5 = 0;
			if (flag5) {
				fig[4]++;
				continue;
			}

			flag5 = 1;
			if (j + 1 >= C || ar[i][j + 1] != c)flag5 = 0;
			else if (j + 2 >= C || ar[i][j + 2] != c)flag5 = 0;
			else if (i + 1 >=R || j + 1 >= C || ar[i + 1][j + 1] != c)flag5 = 0;
			if (flag5) {
				fig[4]++;
				continue;
			}
		}
	}
	for (int i = 0; i < 5; i++) {
		cout << fig[i] << '\n';
	}
}
void solve() {
	input();
	solution();
}
int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	solve();
	return 0;
}