#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int solution(vector<int> numbers) {
	int answer = 0;
	int a[10]; memset(a, 0, sizeof(a));
	for (int i = 0; i < numbers.size(); i++) a[numbers[i]] = 1;
	for (int i = 0; i < 10; i++) {
		if (!a[i])answer += i;
	}
	return answer;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	//vector<int> a = { 1,2,3,4,6,7,8,0 };
	vector<int> a = { 5,8,4,0,6,7,9 };
	cout << solution(a);
	return 0;
}