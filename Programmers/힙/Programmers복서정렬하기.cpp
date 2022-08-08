#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct cmp {
	bool operator()(vector<int> a, vector<int> b){
		if (a[0] == b[0]) {
			if (a[1] == b[1]) {
				if (a[2] == b[2]) return a[3] > b[3];
				return a[2] < b[2];
			}
			return a[1] < b[1];
		}
		return a[0] < b[0];
	}
};
vector<int> solution(vector<int> weights, vector<string> head2head) {
	vector<int> answer;
	priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
	for (int i = 0; i < head2head.size(); i++) {
		int win = 0, win_overweight = 0, draw = 0;
		for (int j = 0; j < weights.size(); j++) {
			if (head2head[i][j] == 'W') {
				win++;
				if (weights[j] > weights[i]) win_overweight++;
			}
			else if (head2head[i][j] == 'N') draw++;
		}
		if (draw == weights.size()) {
			pq.push({ 0, 0, weights[i], i }); continue;
		}
		double percentage = (win * 1000000) / (weights.size() - draw);
		pq.push({(int)percentage, win_overweight, weights[i], i});
	}
	while (!pq.empty()) {
		answer.push_back(pq.top()[3] + 1); pq.pop();
	}
	return answer;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	//vector<int> w = { 50,82,75,120 };
	//vector<string> v = { "NLWL","WNLL","LWNW","WWLN" };

	//vector<int> w = { 145,92,86 };
	//vector<string> v = { "NLW","WNL","LWN" };

	vector<int> w = { 60,70,60 };
	vector<string> v = { "NNN","NNN","NNN" };

	vector<int> a = solution(w, v);
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << endl;
	return 0;
}