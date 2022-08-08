#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> v;
int n;
int sum=0;
 
void dfs(int line){
	if(line==n){
		sum++;return;
	}
	for(int i=0;i<n;i++){
		bool flag = true;
		for(int j=0;j<v.size();j++){
			if(v[j]==i || abs(line-j)==abs(v[j]-i)){
				flag=false;
				break;
			}
		}
		if(flag){
			v.push_back(i);
			dfs(line+1);
			v.pop_back();
		}
	}
}
int main() {
	cin>>n;
	for(int i=0;i<n;i++){
		v.push_back(i);
		dfs(1);
		v.pop_back();
	}
    cout<<sum;
	return 0;
}