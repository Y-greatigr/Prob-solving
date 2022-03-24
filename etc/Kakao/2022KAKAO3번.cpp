#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
	vector<int> answer;
	map<string, int> car;
	map<string, int> time;
	for (int i = 0; i < records.size(); i++) {
		string t = records[i].substr(0, 5);
		string num = records[i].substr(6, 4);
		string p = records[i].substr(11);
		int hour = stoi(t.substr(0, 2));
		int min = stoi(t.substr(3));
		int hour_min = hour * 60 + min;
		if (time[num]) {
			if (time[num] != 1000000) car[num] += (hour_min - time[num]);
			else car[num] += hour_min;
			time.erase(num);
		}
		else {
			if (hour_min) time[num] = hour_min;
			else time[num] = 1000000;
		}
	}
	map<string, int>::iterator it;
	for (it = time.begin(); it != time.end(); it++) {
		if (it->second) { 
			if (it->second != 1000000)car[it->first] += (1439 - it->second);
			else car[it->first] = 1439;
		}
	}

	map<string,int>::iterator itt;
	for (itt = car.begin(); itt != car.end(); itt++) {
		int sum = fees[1];
		if (itt->second <= fees[0]) {
			answer.push_back(sum); continue;
		}
		if ((itt->second - fees[0]) % fees[2]) sum += (((itt->second - fees[0]) / fees[2]) + 1) * fees[3];
		else sum += ((itt->second - fees[0]) / fees[2]) * fees[3];
		answer.push_back(sum);
	}
	return answer;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	/*vector<int> a = { 180, 5000, 10, 600 };
	vector<string> b = { "05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT" };
	vector<int> c = solution(a, b);
	*/
	/*vector<int> a = { 120, 0, 60, 591 };
	vector<string> b = { "16:00 3961 IN","16:00 0202 IN","18:00 3961 OUT","18:00 0202 OUT","23:58 3961 IN" };
	vector<int> c = solution(a, b);
	*/
	vector<int> a = { 1, 461, 1, 10 };
	vector<string> b = { "00:00 1234 IN" };
	vector<int> c = solution(a, b);
	for (int i = 0; i < c.size(); i++)
		cout << c[i] << endl;
	return 0;
}