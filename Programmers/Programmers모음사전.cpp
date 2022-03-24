#include <iostream>
#include <string>
#include <vector>

using namespace std;
int dic(char a) {
	if (a == 'A')return 1;
	else if (a == 'E')return 782;
	else if (a == 'I')return 1563;
	else if (a == 'O')return 2344;
	else return 3125;
}
int dic(char a, char b) {
	int sum = dic(a);
	if (b == 'A') sum += 1;
	else if (b == 'E')sum += 157;
	else if (b == 'I')sum += 313;
	else if (b == 'O')sum += 469;
	else sum += 625;
	return sum;
}
int dic(char a, char b, char c) {
	int sum = dic(a, b);
	if (c == 'A') sum += 1;
	else if (c == 'E')sum += 32;
	else if (c == 'I')sum += 63;
	else if (c == 'O')sum += 94;
	else sum += 125;
	return sum;
}
int dic(char a, char b, char c, char d) {
	int sum = dic(a, b, c);
	if (d == 'A') sum += 1;
	else if (d == 'E')sum += 7;
	else if (d == 'I')sum += 13;
	else if (d == 'O')sum += 19;
	else sum += 25;
	return sum;
}
int dic(char a, char b, char c, char d, char e) {
	int sum = dic(a, b, c, d);
	if (e == 'A') sum += 1;
	else if (e == 'E')sum += 2;
	else if (e == 'I')sum += 3;
	else if (e == 'O')sum += 4;
	else sum += 5;
	return sum;
}
int solution(string word) {
	int size = word.length();
	if (size == 1) return dic(word[0]);
	else if (size == 2) return dic(word[0],word[1]);
	else if (size == 3) return dic(word[0], word[1], word[2]);
	else if (size == 4) return dic(word[0], word[1], word[2], word[3]);
	else return dic(word[0], word[1], word[2], word[3], word[4]);
	return 0;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string a = "UUUUU";
	cout << solution(a);
	return 0;
}