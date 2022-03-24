#include <iostream>
#include <vector>

using namespace std;

int a[10000];
int aa[4];
void dfs(int cur, int length, vector<vector<int>> dice) {
    a[cur] = 1;
    if (length == dice.size())return;
    for (int i = 0; i < dice.size(); i++) {
        if (aa[i])continue;
        aa[i] = 1;
        for (int j = 0; j < 6; j++) {
            int b = cur * 10 + dice[i][j];
            dfs(b, length + 1, dice);
        }
        aa[i] = 0;
    }
}
int solution(vector<vector<int>> dice) {
    int answer = 0;
    for (int i = 0; i < dice.size(); i++) {
        aa[i] = 1;
        for (int j = 0; j < 6; j++) {
            if (dice[i][j] == 0)continue;
            dfs(dice[i][j], 1, dice);
        }
        aa[i] = 0;
    }
    for (int i = 1; i < 1000; i++) {
        if (!a[i]) {
            answer = i; break;
        }
    }
    return answer;
}
int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    vector<vector<int>> v = { {0, 1, 9, 8, 7, 6} };
    //vector<vector<int>> v = { {1, 6, 2, 5, 3, 4} ,{9, 9, 1, 0, 7, 8} };
    //vector<vector<int>> v = { {0, 1, 5, 3, 9, 2} ,{2, 1, 0, 4, 8, 7}, {6, 3, 4, 7, 6, 5} };
    cout << solution(v);
    return 0;
}