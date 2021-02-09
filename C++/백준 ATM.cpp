#include <iostream>
#include <string>
#include <vector>
using namespace std;
int min(int p[], int N) {
	int time=0, sum=0;
	int tmp;
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			if (p[i] < p[j]) {
				tmp = p[i];
				p[i] = p[j];
				p[j] = tmp;
			}
		}
	}
	for (int i = 1; i < N + 1; i++) {
		time += p[i];
		sum += time;
	}

	return sum;
}
int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	int P[1001];
	for (int i = 1; i < N+1; i++)
		cin >> P[i];

	cout << min(P,N);
	return 0;
}