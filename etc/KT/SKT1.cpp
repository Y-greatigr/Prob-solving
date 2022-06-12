#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> p) {
    vector<int> answer;
    int ar[1000]={0,};
    int i=0;
    while(i<p.size()){
        int j=min_element(p.begin()+i+1,p.end())-p.begin();
        if(j>=p.size())break;
        int min=*min_element(p.begin()+i+1,p.end());
        if(p[i]>min){
            int tmp=p[i];
            p[i]=min;
            p[j]=tmp;
            ar[i]++, ar[j]++;
            cout<<i<<" "<<j<<endl;
        }
        i++;
    }
    for(int i=0;i<p.size();i++)answer.push_back(ar[i]);
    return answer;
}