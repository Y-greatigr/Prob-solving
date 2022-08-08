#include <iostream>
#include <string>
#include <vector>
using namespace std;
int min(int k, vector<int> a) {

	int num = 0;
	int b = k;
	for (int i = a.size()-1; i >= 0; i--) {
		if (b < a[i])
			continue;
		b = b - a[i++];
		num++;
	}
	return num;
}
int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, K,b;
	cin >> N >> K;

	vector<int> a;
	for (int i = 0; i < N; i++) {
		cin >> b;
		a.push_back(b);
	}

	cout<<min(K, a);
	return 0;
}