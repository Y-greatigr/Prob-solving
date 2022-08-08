#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
	sort(citations.begin(), citations.end());
	int maxi = 0;
	for (int i = 1; i <= citations.size(); i++) {
		int j;
		for (j = 0; j < citations.size(); j++) {
			if(citations[j]>=i)				// h번 이상 인용된 논문
				break;
		}
		if (citations.size() - j >= i) {	// h번 이하 인용된 논문
			if (maxi < i)
				maxi = i;
		}
	}
	return maxi;
}
int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	vector<int> b(5);
	b = { 3, 0, 6, 1, 5 };

	cout << solution(b);
	return 0;
}