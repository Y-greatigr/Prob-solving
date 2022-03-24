#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b) {
	return a.second > b.second;
}
vector<int> solution(vector<string> genre, vector<int> play) {
	vector<int> answer;
	map<string, int> count;
	vector <pair<string, int>> v;

	for (int i = 0; i < genre.size(); i++)
		count[genre[i]] += play[i];
	map<string, int>::iterator iter = count.begin();
	for (iter = count.begin(); iter != count.end(); ++iter)
		v.push_back(make_pair(iter->first, iter->second));

	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++) {
		int f = 0; int s = 0; int fn = 0; int sn = 0;
		for (int j = 0; j < genre.size(); j++) {
			if (genre[j] == v[i].first) {
				if (play[j] > f) {
					s = f;
					sn = fn;
					f = play[j];
					fn = j;
				}
				else if (play[j] > s) {
					s = play[j];
					sn = j;
				}
			}
		}
		answer.push_back(fn);
		if (s > 0)
			answer.push_back(sn);
	}
	return answer;
}
int main() {
    int N;

    cin >> N;

    vector<string> genre;
    vector<int> play;
    string a;
    int b;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        genre.push_back(a);
        play.push_back(b);
    }
    vector<int> c=solution(genre, play);
    for (int i = 0; i < c.size(); i++)
        cout << c[i]<<"\n";

	return 0;
}