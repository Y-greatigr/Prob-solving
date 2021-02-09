#include <iostream>

using namespace std;
int arr[10][1000];
void swap(int k, int i, int j) {
	int tmp = arr[k][i];
	arr[k][i] = arr[k][j];
	arr[k][j] = tmp;
}
void sort(int k, int n) {
	int i = n - 1;
	while (i > 0 && arr[k][i] <= arr[k][i - 1])
		i -= 1;
	if (i <= 0) {
		for (int j = 1; j <= n; j++)
			arr[k][j - 1] = j;
	}
		
	int j = n - 1;
	while (arr[k][i - 1] >= arr[k][j])
		j -= 1;
	swap(k, i - 1, j);                // 찾은 수의 바로 앞 swap i-1 
	j = n - 1;                        // j는 마지막 
	while (i < j) {                    // i-1 이후로, swap해줌 
		swap(k, i, j);
		i += 1;
		j -= 1;
	}
}
int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;

	for (int i = 0; i < K; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
		sort(i, N);
	}
	for(int i=0;i< K; i++) {
		for (int j = 0; j < N; j++) {
			cout << arr[i][j]<<" ";
		}
		cout << "\n";
	}
	return 0;
}