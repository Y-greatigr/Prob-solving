#include <iostream>
using namespace std;
int a[1000];
int b[1000];
int bst(int start, int end, int target) {
	while (start < end) {
		int mid = (start + end) / 2;
		if (b[mid] < target)
			start = mid + 1;
		else if (b[mid] > target)
			end = mid;
		else
			return -1;
	}
	return end;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n; cin >> n;
	int i, j;
	for (i = 0; i < n; i++)
		cin >> a[i];
	i = 1, j = 0;
	b[0] = a[0];
	while (i < n) {
		if (b[j] < a[i]) {
			b[j + 1] = a[i];
			j++;
		}
		else {
			int ind = bst(0, j, a[i]);
			if(ind!=-1)
				b[ind] = a[i];
		}
		i++;
	}
	cout << j + 1;
	return 0;
}