#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

vector<int> solution(vector<int> periods, vector<vector<int>> payments, vector<int> estimates) {
    vector<int> answer;
    int ar[2]={0,};
    for(int i=0;i<periods.size();i++){
        int sum= accumulate(payments[i].begin(),payments[i].end(),0);
        bool flag=((periods[i]>=24 && sum>=900'000) || (periods[i]>=60 && sum>=600'000))?true: false;
        if(periods[i]>=12)sum-=payments[i][0];
        sum+=estimates[i];
        bool flag2=((periods[i]+1>=24 && sum>=900'000) || (periods[i]+1>=60 && sum>=600'000))?true: false;
        if(!flag && flag2)ar[0]++;
        if(flag && !flag2)ar[1]++;
    }
    answer.push_back(ar[0]), answer.push_back(ar[1]);
    return answer;
}