#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

int solution(int size) {
	int answer = 0;
	map <tuple<int, int, int>, int> m;
	for (int i = 1; i < size - 1; i++) {
		int b = size-i;
		if (i > size / 2)break;
		for (int j = 1; j < b; ++j) {
			int c = b - j;
			if (j >= i + c)break;
			int s1, s2, s3;
			if (i > j) {
				if (i > c) {
					s1 = i;
					if (j > c) { s2 = j; s3 = c; }
					else { s2 = c; s3 = j; }
				}
				else {
					s1 = c; s2 = i; s3 = j;
				}
			}
			else {
				if (j > c) {
					s1 = j;
					if (i > c) { s2 = i; s3 = c; }
					else { s2 = c; s3 = i; }
				}
				else {
					s1 = c; s2 = j; s3 = i;
				}
			}
			if (s1 < (s2 + s3) && m.find({ s3, s2, s1 }) == m.end()) {
				answer++; m[{s3, s2, s1}] = 1;
			}
		}
	}
	return answer;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cout << solution(9);
	//cout << solution(12);

	return 0;
}