#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;


int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string input;
	int i = 1;
	string a = "ABC";
	string b="B";
	
	string str;
	str.append("(");
	str += a[0];
	str.append("+");
	str += b;
	str.append(")");
	cout << str;

	input.push_back('a');
	input.push_back('b');
	input.push_back('c');

	cout << input[input.size()-1] << endl;


	return 0;
}