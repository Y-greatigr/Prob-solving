/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int T, test_case;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */

	 // freopen("input.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		string b;
		int n, t;
		cin >> n >> t;
		cin >> b;
		string a = "";
		for (int i = 0; i < n; i++) {
			a += "0";
		}
		for (int i = 0; i < n; i++) {
			if (i - t >= 0 && a[i - t] == '1') {
					continue;
			}
			if (i + t < n) {
				if (a[i + t] == '1' || b[i]=='0')
					continue;
				if (i + t + t < n) {
					if (b[i + t + t] == '0')
						a[i - t] = '1';
					else
						a[i + t] = '1';
				}
				else
					a[i + t] = '1';
			}
			else {
				if(b[i]=='1')
					a[i - t] = '1';
			}
		}
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		 /////////////////////////////////////////////////////////////////////////////////////////////

		 // Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << a << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}