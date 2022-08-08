#include <iostream>
#include <vector>

using namespace std;
vector<int> a;
int Max_Near(int m) {
	int max_near = 10;
	int d;
	for (int i = 0; i < a.size(); i++) {
		for (int j = i+1; j < a.size(); j++) {
			for (int k = j+1; k < a.size(); k++) {
				d = a[i] + a[j] + a[k];
				if (d <= m)
					if (d > max_near)
						max_near = d;
			} 
		}
	}
	return max_near;
}
int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int N, M, b;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> b;
		a.push_back(b);
	}

	cout << Max_Near(M);

	return 0;
}