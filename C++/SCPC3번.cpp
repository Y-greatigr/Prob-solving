/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

int Answer;
int web[501];
vector<pair<int,string>> no_web[501];
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
		int N, M, K; cin >> N >> M >> K;
		int a, b;
		memset(web, 0, sizeof(web));
		for (int i = 0; i < M; i++) {
			cin >> a >> b;
			web[a] = b;
		}
		for (int i = 0; i < K; i++) {
			cin >> a >> b;
			no_web[a].push_back({ b,"0"});
			no_web[b].push_back({ a,"1"});
		}
		queue<int> q;
		q.push(1);
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			if (web[cur]) {
				if (int k=no_web[cur].size()) {
					for (int i = 0; i < k; i++) {
						//q.push()
					}
				}
				//q.push()
			}
		}
		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		 /////////////////////////////////////////////////////////////////////////////////////////////

		 // Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}