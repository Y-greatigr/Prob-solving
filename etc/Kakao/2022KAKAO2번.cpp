#include <iostream>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

//long long a[10000001];
bool conf(long long a) {
	if (a == 1 || a == 0)return false;
	if (a > 10000000000) {
		for (long long i = a/2; i < a; i++) {
			if (!(a % i))return false;
		}
	}
	else {
		for (long long i = 2; i < a; i++) {
			if (!(a % i))return false;
		}
	}
	return true;
}
int solution(int n, int k) {
	int answer = 0;
	/*memset(a, 0, sizeof(a));
	a[0] = 1; a[1] = 1;
	for (long long i = 2; i < 5000000; i++) {
		for (int j = 2; j <= 5000000; j++) {
			if (i * j > 10000000) break;
			a[i * j] = 1;
		}
	}*/
	string b = "", c = "";
	while (n) {
		int j = n % k;
		n = n / k;
		b += to_string(j);
	}
	for (int i = b.length() - 1; i >= 0; i--) c += b[i];
	//cout << c << endl;
	while (1) {
		int ind = c.find("0");
		if (ind == string::npos) {
			//if (!a[stol(c)]) answer++;
			if (conf(stol(c))) answer++;
			break; 
		}
		string d = c.substr(0, ind);
		//if (ind!=0 && !a[stol(d)]) { answer++; }
		if (ind!=0 && conf(stol(d))) { answer++; }
		if (ind >= c.length() - 1) break;
		c = c.substr(ind + 1);
	}

	return answer;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	//int n = 437674, k = 3;
	//int n = 11001100, k = 10;
	//int n = 9, k = 3;
	int n = 1000000, k = 4;

	cout << solution(n, k);
	return 0;
}