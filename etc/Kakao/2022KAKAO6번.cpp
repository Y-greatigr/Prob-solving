#include <iostream>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
	int answer = 0;
	for (int i = 0; i < skill.size(); i++) {
		int k = (skill[i][0] == 1) ? -1 : 1;
		for (int x = skill[i][1]; x <= skill[i][3]; x++) {
			for (int y = skill[i][2]; y <= skill[i][4]; y++) {
				board[x][y] += skill[i][5]*k;
			}
		}
	}
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			if (board[i][j] > 0)answer++;
		}
	}
	return answer;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	/*
	vector<vector<int>> a = { {5,5,5,5,5},{5,5,5,5,5}, {5,5,5,5,5}, {5,5,5,5,5}};
	vector<vector<int>> b = { {1,0,0,3,4,4} ,{1,2,0,2,3,2},{2,1,0,3,1,2},{1,0,1,3,3,1}};
	*/
	
	vector<vector<int>> a = { {1,2,3},{4,5,6}, {7,8,9}};
	vector<vector<int>> b = { {1,1,1,2,2,4} ,{1,0,0,1,1,2},{2,2,0,2,0,100}};
	
	cout << solution(a, b);
	return 0;
}