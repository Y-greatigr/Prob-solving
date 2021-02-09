#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
vector<int> v;
int ar[8001] = { 0, };
bool com(int i, int j) {
	return i < j;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	v.resize(n);
	
	double sum = 0;
	int max = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		sum += v[i];
		ar[v[i] + 4000]++;
		if (ar[v[i] + 4000] > max)
			max = ar[v[i] + 4000];
	}
	stable_sort(v.begin(), v.end(), com);
	cout << round(sum / (double)n) << '\n'; //»ê¼úÆò±Õ
	cout << v[n / 2] << '\n'; //Áß¾Ó°ª

	int casa = 4000;
	bool second = false;
	for (int i = 0; i <= 8000; i++) {
		if (ar[i] == max) {
			casa = i - 4000;
			if (second)
				break;
			second = true;
		}
	}
	cout << casa << '\n'; //ÃÖºó°ª
	if (n > 1)
		cout << v[n - 1] - v[0]; //¹üÀ§
	else
		cout << 0;
	return 0;
}