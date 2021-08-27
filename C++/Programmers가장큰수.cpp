#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(string a, string b){
	return a + b > b + a;
}
string solution(vector<int> numbers) {
	string answer = "";
	vector<string> a;
	for (int i = 0; i < numbers.size(); i++)
		a.push_back(to_string(numbers[i]));
	sort(a.begin(), a.end(), cmp);
	for (int i = 0; i < a.size(); i++)
		answer += a[i];
	if (answer[0] == '0')
		return "0";
	return answer;
}
int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	vector<int> b(5);
	b = { 3, 30, 34, 5, 9 };

	cout << solution(b);
	return 0;
}