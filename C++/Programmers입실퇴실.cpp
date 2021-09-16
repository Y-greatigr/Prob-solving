#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<int> enter, vector<int> leave) {
	vector<int> answer(enter.size());
	int e = 0, l = 0;
	map<int, int> m;
	while (e < enter.size() || l < leave.size()) {
		m[enter[e]] = 1;
		if (m.size()>1) { 
			map<int, int>::iterator it;
			for (it = m.begin(); it != m.end(); it++)answer[it->first - 1]++;
			answer[enter[e] - 1] += (m.size() - 2);
		}
		while(l<leave.size() && m.find(leave[l])!=m.end()) {	
			m.erase(leave[l]); 
			l++;
		}
		e++;
	}
	return answer;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	/*
	vector<int> a = { 1,3,2 };
	vector<int> b = { 1,2,3 };
	*/
	
	vector<int> a = { 1,4,2,3 };
	vector<int> b = { 2,1,3,4 };
	

	vector<int> c = solution(a, b);
	for (int i = 0; i < c.size(); i++)
		cout << c[i] << endl;
	return 0;
}