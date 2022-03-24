#include <iostream>
#include <vector>
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
	int check[101][101];
	for (int j = 1; j <= n; j++) //¹è¿­ ÃÊ±âÈ­
		for (int i = 1; i <= m; i++)
			check[j][i] = 1;

	for (int i = 0; i < puddles.size(); i++) { //¹°¿õµ¢ÀÌ´Â 0À¸·Î Ã¼Å©)
		check[puddles[i][1]][puddles[i][0]] = 0;
		if (puddles[i][0] == 1) {
			for (int j = puddles[i][1]; j <= n; j++)
				check[j][1] = 0;
		}
		if (puddles[i][1] == 1) {
			for (int j = puddles[i][0]; j <= m; j++)
				check[1][j] = 0;
		}
	}

	for (int i = 2; i <= m; i++) { //¿ÞÂÊÄ­, À§Ä­ °ª ´õÇØ³ª°¡¸é¼­ °ª ±¸ÇÏ±â
		for (int j = 2; j <= n; j++) {
			if (check[j][i] != 0) //¹°¿õµ¢ÀÌ Á¦¿Ü
				check[j][i] = (check[j - 1][i] + check[j][i - 1]) % 1000000007;
		}
	}
	return check[n][m];
}
int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);
    int m, n, N, x, y;
    vector<vector<int>> puddle;
	vector<int> puddle_xy[101];

    cin >> m >> n;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        puddle_xy[i].push_back(x);
        puddle_xy[i].push_back(y);
		puddle.push_back(puddle_xy[i]);
    }
    cout<<solution(m, n, puddle);
	return 0;
}