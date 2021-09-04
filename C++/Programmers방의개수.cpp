#include <iostream>
#include <vector>
#include <map>

using namespace std;

int row[8] = { -1,-1,0,1,1,1,0,-1 };
int col[8] = { 0,1,1,1,0,-1,-1,-1 };
int solution(vector<int> arrows) {
	int answer = 0;
	map<pair<int, int>,int> n;
	map<pair<pair<int, int>, pair<int, int>>, int> e;
	
	int row_cur = 0, col_cur = 0;
	n.insert({ { row_cur,col_cur }, 1 });
	for (int i = 0; i < arrows.size(); i++) {
		int k = 2;
		while (k--) {
			int r = row_cur + row[arrows[i]];
			int c = col_cur + col[arrows[i]];
			if (n[{r, c}] && !e[{ {row_cur, col_cur}, { r,c }}]) {
				e[{ {row_cur, col_cur}, { r,c }}] = 1;
				e[{ {r, c}, { row_cur,col_cur }}] = 1;
				row_cur = r; col_cur = c;
				answer++; continue;
			}
			n[{r, c}] = 1;
			e[{ {row_cur, col_cur}, { r,c }}] = 1;
			e[{ {r, c}, { row_cur,col_cur }}] = 1;
			row_cur = r; col_cur = c;
		}
	}
	return answer;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	//vector<int> a = { 6, 6, 6, 4, 4, 4, 2, 2, 2, 0, 0, 0, 1, 6, 5, 5, 3, 6, 0 };
	vector<int> a = { 6,0,2,4,2,0,6,4 };
	cout << solution(a);
	return 0;
}