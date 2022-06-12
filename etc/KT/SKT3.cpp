#include <iostream>
#include <string>
#include <vector>

using namespace std;

int price[300'001]={0,};
int plus_service[300'001]={0,};
vector<int> solution(int n, vector<string> plans, vector<string> clients) {
    vector<int> answer;
    for(int i=0;i<plans.size();i++){
        int ind=plans[i].find(" ");
        price[i+1]=stoi(plans[i].substr(0, ind));
        string s=plans[i].substr(ind+1);
        while(true){
            ind=s.find(" ");
            if(ind==string::npos){
                plus_service[stoi(s)]=i+1;
                break;
            }
            plus_service[stoi(s.substr(0, ind))]=i+1;
            s=s.substr(ind+1);
        }
    }
    for(int i=0;i<clients.size();i++){
        int ind=clients[i].find(" ");
        int cli_price=stoi(clients[i].substr(0, ind));
        vector<int> cli_service;
        string s=clients[i].substr(ind+1);
        while(true){
            ind=s.find(" ");
            if(ind==string::npos){
                cli_service.emplace_back(stoi(s));
                break;
            }
            cli_service.emplace_back(stoi(s.substr(0, ind)));
            s=s.substr(ind+1);
        }
        int num=0;
        for(int j=1;j<=n;j++){
            bool flag=true;
            if(cli_price<=price[j]){
                for(int k=0;k<cli_service.size();k++){
                    if(plus_service[cli_service[k]]>j || plus_service[cli_service[k]]==0){
                        flag=false;
                        break;
                    }
                }
            }
            else flag=false;
            if(flag){
                num=j;
                break;
            }
        }
        answer.push_back(num);
    }
    return answer;
}