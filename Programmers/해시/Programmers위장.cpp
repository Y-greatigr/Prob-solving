#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
	int answer = 1;
	map<string, int> m;
	for (int i = 0; i < clothes.size(); i++) {
		if (m.find(clothes[i][1]) == m.end()) {
			m.insert({ clothes[i][1], 1 });
			continue;
		}
		m[clothes[i][1]]++;
	}
	map<string, int>::iterator it;
	for (it = m.begin(); it != m.end(); it++) {
		answer *= (it->second + 1);
	}
	return answer - 1;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	vector<vector<string>> a;
	vector<string> b;
	
	b.push_back("yellow");
	b.push_back("d");
	a.push_back(b);
	b.clear();

	b.push_back("blue");
	b.push_back("d");
	a.push_back(b);
	b.clear();

	b.push_back("green");
	b.push_back("d");
	a.push_back(b);
	b.clear();

	cout << solution(a);
	return 0;
}