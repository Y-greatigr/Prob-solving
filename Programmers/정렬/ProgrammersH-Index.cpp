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
			if(citations[j]>=i)				// h�� �̻� �ο�� ��
				break;
		}
		if (citations.size() - j >= i) {	// h�� ���� �ο�� ��
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