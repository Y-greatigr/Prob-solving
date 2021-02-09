#include <iostream>

using namespace std;

void merge(int left, int mid, int right, int* a, int* b) {
	int k = left, x = left;
	int y = mid + 1;
	while (x <= mid && y <= right) {
		if(a[x]<a[y])
			b[k++] = a[x++];
		else
			b[k++] = a[y++];
	}
	int tmp = (x > mid) ? y : x;

	while (k <= right) {
		b[k++] = a[tmp++];
	}

	for (int i = left; i <= right; i++) {
		a[i] = b[i];
	}
}
void partition(int le, int ri, int*a, int*b) {
	if (le >= ri)
		return;
	int mid = (le + ri) / 2;

	partition(le, mid, a, b);
	partition(mid + 1, ri, a, b);
	merge(le, mid, ri, a, b);
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int N;
	cin >> N;
	int* a = new int[N];
	int* b = new int[N];
	for (int i = 0; i < N; i++)
		cin >> a[i];
	partition(0, N-1, a, b);
	for (int i = 0; i < N; i++)
		cout << a[i] << '\n';
	delete[]a;
	delete[]b;
	return 0;
}