#include <iostream>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

bool visited[10000] = { false };
string bfs(int a, int b) {
	memset(visited, false, sizeof(visited));
	queue<pair<int, string>> q;
	q.push({ a, "" });
	visited[a] = true;
	while (!q.empty()) {
		int ho = q.front().first;
		string wow = q.front().second;
		q.pop();
		if (ho == b)
			return wow;
		int yo = (2 * ho) % 10000;
		if (!visited[yo]) {
			visited[yo] = true;
			q.push({ yo, wow + "D" });
		}
		yo = (ho == 0) ? 9999 : ho - 1;
		if (!visited[yo]) {
			visited[yo] = true;
			q.push({ yo, wow + "S" });
		}
		yo = (ho % 1000) * 10 + ho / 1000;
		if (!visited[yo]) {
			visited[yo] = true;
			q.push({ yo, wow + "L" });
		}
		yo = ho / 10 + (ho % 10) * 1000;
		if (!visited[yo]) {
			visited[yo] = true;
			q.push({ yo, wow + "R" });
		}
	}
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n; cin >> n;
	while (n--) {
		int a, b; cin >> a >> b;
		cout << bfs(a, b) << '\n';
	}
	return 0;
}

/*#include <iostream>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

int A,B;
bool check[10000];
int T;
int m[10000];

bool f;
int _op(int op, int num){
	int ret = num;
	if(op == 1){
		ret*=2;
		if(ret>9999) ret %= 10000;
	}
	else if(op == 2){
		if(ret == 0) ret = 9999;
		else ret -= 1;
	}
	else if(op==3){
		int temp = ret/1000;
		ret = (ret%1000)*10;
		ret += temp;
	}
	else{
		int temp = ret%10;
		ret /= 10;
		ret = ret + temp*1000;
	}
	
	return ret;
}
void bfs(int st, queue<int>& q){
	check[st] = true;
	q.push(st);
	f= false;
	while(!q.empty()){
		int cur = q.front(); q.pop();
		
		for(int i=1;i<=4;i++){
			int next = _op(i,cur);
			if(check[next]) continue;
			m[next] = cur;
			check[next]=true;
			q.push(next);
			if(next == B){
				f = true;
				break;
			}
		}
		if(f) break;
	}
	
}
int main(int argc, char *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> T;
	for(int tc =0; tc <T; tc++){
		cin >> A >> B;
		memset(check,false,sizeof(check));
		queue<int> q;
		int st = A;
		bfs(A,q);
		string ans="";
		int key = B;
		while(key != A){
			int temp = m[key];
			for(int i=1;i<=4;i++){
				if(key == _op(i,temp)){
					if(i==1) ans.push_back('D');
					else if(i==2) ans.push_back('S');
					else if(i==3) ans.push_back('L');
					else if(i==4) ans.push_back('R');
					break;
				}
			}
			key = temp;
		}
		for(int i=ans.size()-1;i>=0;i--){
			cout << ans[i];
		}
		cout << '\n';		
	}
}*/


/*#include <stdio.h>
#include <string.h>
#include <malloc.h>

int q[65536], dist[10240], op[10240], vis[10240], d[10240], s[10240], l[10240], r[10240], p[10240];
int qf = 0, qr = 0, br = 0, bn = 0;
char path[10240];
char dslr[] = "DSLR";

void bfs(int a, int b) {
    int x, y, z, w, f, st = a;
    q[qr++] = a;
    vis[a] = 1;
    while (qr - qf) {
        a = q[qf++];
        x = d[a];
        y = s[a];
        z = l[a];
        w = r[a];
        if (!vis[x]) {
            q[qr++] = x;
            vis[x] = 1;
            dist[x] = dist[a] + 1;
            op[x] = 1;
            if (x == b) break;
        }
        if (!vis[y]) {
            q[qr++] = y;
            vis[y] = 1;
            dist[y] = dist[a] + 1;
            op[y] = 2;
            if (y == b) break;
        }
        if (!vis[z]) {
            q[qr++] = z;
            vis[z] = 1;
            dist[z] = dist[a] + 1;
            op[z] = 3;
            if (z == b) break;
        }
        if (!vis[w]) {
            q[qr++] = w;
            vis[w] = 1;
            dist[w] = dist[a] + 1;
            op[w] = 4;
            if (w == b) break;
        }
    }
    f = b;
    path[dist[f]] = '\0';
    while (f != st) {
        path[dist[f] - 1] = dslr[op[f] - 1];
        if (op[f] == 1) {
            if ((dist[f] > 1 && dist[f >> 1] == dist[f] - 1) || (f >> 1 == st)) f = f >> 1;
            else if (dist[(f >> 1) + 5000] == dist[f] - 1) f = (f >> 1) + 5000;
        }
        else if (op[f] == 2) f = p[f];
        else if (op[f] == 3) f = r[f];
        else if (op[f] == 4) f = l[f]
        //else exit(1);
    }
    if (qr > br) {
        br = qr;
        bn = b;
    }
}

int main(void) {
    int t, a, b, f;
    for (int i = 0; i < 10000; i++) {
        d[i] = (i << 1) % 10000;
        s[i] = (i + 9999) % 10000;
        l[i] = (i % 1000) * 10 + i / 1000;
        r[i] = i / 10 + (i % 10) * 1000;
        p[i] = (i + 1) % 10000;
    }

    scanf("%d", &t);
    if (t > 10000) return 1;
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &a, &b);
        if (a == b) continue;
        bfs(a, b);
        printf("%s\n", path);
        path[0] = '\0';
        qf = 0;
        qr = 0;
        memset(vis, 0, 40000);
        memset(dist, 0, 40000);
    }
    return 0;
}*/