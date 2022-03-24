#include <iostream>
#include <vector>
using namespace std;
 
vector<vector<int>> v(16, vector<int>(16, 0));
vector<vector<pair<int,int>>> memo;
int n;
int sum=0;
 
void ch1(int row, int col){
	vector<pair<int,int>> m;
	for(int i=1;i<=n;i++){
		if(v[row][i]!=1){
			m.push_back({row, i});
			v[row][i]=1;
		}
		if(v[i][col]!=1){
			m.push_back({i, col});
			v[i][col]=1;
		}
		int a=i+col;
        if(row+i>n)continue;
		if(a<=n && v[row+i][a]!=1) {
			m.push_back({row+i, a});
			v[row+i][a]=1;
		}
		int b=col-i;
		if(b>0 && v[row+i][b]!=1){
			m.push_back({row+i, b});
			v[row+i][b]=1;
		}
	}
	memo.push_back(m);
}
void ch2(int row, int col){
	vector<pair<int,int>> m=memo[memo.size()-1];
	for(int i=0;i<m.size();i++){
		v[m[i].first][m[i].second]=0;
	}
}
void dfs(int line){
    if(line>n){
        return;
    }
	for(int i=1;i<=n;i++){
		if(v[line][i]!=1){
			if(line==n){sum++;continue;}
			ch1(line, i);
			dfs(line+1);
			ch2(line, i);
			memo.pop_back();
		}
	}
}
int main() {
	cin>>n;
	for(int i=1;i<=n;i++)v[1][i]=1;
    for(int i=1;i<=n;i++){
        ch1(1, i);dfs(2);ch2(1, i);memo.pop_back();
	}
    cout<<sum;
	return 0;
}