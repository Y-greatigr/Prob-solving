/**
 * 문제 설명
당신은 온라인으로 문제를 풀 수 있는 웹 페이지 관리자입니다. 당신은 유저를 위해 웰 노운 문제를 선별하는 작업을 진행하고 있습니다.

한 문제 이상 푼 유저 중 절반 이상이 푼 문제는 웰 노운(Well-Known) 이라고 합니다.

당신은 모든 유저들의 제출 기록 중 문제 풀이에 성공한 기록이 주어졌을 때, 웰 노운 문제를 선별하여 웰 노운 문제 목록을 만드려 합니다. 웰 노운 문제 목록은 사전 순으로 정렬되어야 하며 문제 이름이 중복되지 않습니다.

문제 풀이에 성공한 제출 기록은 “유저_이름 문제_제목" 형태입니다. 유저 이름과 문제 제목이 공백 하나로 구분된 문자열입니다. 예를 들어, “morgan string_compare”라는 기록은 morgan 유저가 string_compare 문제를 풀었음을 의미합니다.

유저들의 문제 풀이에 성공한 제출 기록이 다음과 같다고 가정해보겠습니다.

["morgan string_compare", "felix string_compare", "morgan reverse", "rohan sort", "andy reverse", "morgan sqrt"]

한 문제 이상 푼 유저는 morgan, felix, rohan, andy 네 명입니다. 유저들이 푼 문제는 string_compare, sort, reverse, sqrt 입니다.

각 문제별로 푼 유저 수는 다음과 같습니다.

문제 이름	푼 유저 수
"string_compare"	2
"reverse"	2
"sort"	1
"sqrt"	1
string_compare 문제와 reverse 문제는 한 문제 이상 푼 유저의 절반 이상이 풀었기 때문에 웰 노운 문제입니다. 나머지 문제는 절반 미만이 풀었기 때문에 웰 노운 문제가 아닙니다.

따라서 웰 노운 문제 제목을 사전 순으로 정렬한 결과인 ["reverse", "string_compare"] 가 웰노운 문제 목록입니다.

유저들의 문제 풀이에 성공한 제출 기록을 담은 문자열 배열 logs가 매개변수로 주어질 때, 사전 순으로 정렬된 웰 노운 문제 목록 배열을 return 하도록 solution 함수를 완성해주세요.

제한사항
1 ≤ logs의 길이 ≤ 100
logs의 원소는 "A B" 형식입니다.
A는 유저 이름, B는 문제 제목을 뜻합니다.
1 ≤ A의 길이 ≤ 20
A는 알파벳 소문자로만 이루어져 있습니다.
1 ≤ B의 길이 ≤ 20
B는 알파벳 소문자와 _ 문자로 이루어져 있습니다.
한 유저가 동일한 문제를 여러 번 해결한 경우도 주어집니다. 즉, 동일한 원소가 여러개 있을 수 있습니다.
항상 웰 노운 문제가 한 개 이상 있는 입력만 주어집니다.
입출력 예
logs	result
["morgan string_compare", "felix string_compare", "morgan reverse", "rohan sort", "andy reverse", "morgan sqrt"]	["reverse", "string_compare"]
["morgan sort", "felix sort", "morgan sqrt", "morgan sqrt", "rohan reverse", "rohan reverse"]	["sort"]
["kate sqrt"]	["sqrt"]
입출력 예 설명
입출력 예 #1

문제 예시와 동일합니다.

입출력 예 #2

한 문제 이상 푼 유저는 morgan, felix, rohan, 세 명입니다. 유저들이 푼 문제는 sort, reverse, sqrt 입니다.

각 문제별로 푼 유저 수는 다음과 같습니다.

문제 이름	푼 유저 수
"sort"	2
"reverse"	1
"sqrt"	1
sort 문제는 한 문제 이상 푼 유저의 절반 이상이 풀었기 때문에 웰 노운 문제입니다. 나머지 문제는 절반 미만이 풀었기 때문에 웰 노운 문제가 아닙니다.

따라서 웰 노운 문제 제목을 사전 순으로 정렬한 결과인 ["sort"] 를 return 해야 합니다.

입출력 예 #3

한 문제 이상 푼 유저는 kate, 한 명입니다. 유저들이 푼 문제는 sqrt 입니다.

각 문제별로 푼 유저 수는 다음과 같습니다.

문제 이름	푼 유저 수
"sqrt"	1
sqrt 문제는 한 문제 이상 푼 유저의 절반 이상이 풀었기 때문에 웰 노운 문제입니다.

따라서 웰 노운 문제 제목을 사전 순으로 정렬한 결과인 ["sqrt"] 를 return 해야 합니다.
 */

#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> logs) {
    vector<string> answer;
    map<string,int> m_user;
    map<string,int> m_title;
    map<string,int> uniq;
    for(auto i:logs){
        if(uniq.find(i)!=uniq.end())continue;
        uniq[i]=1;
        int ind=i.find(' ');
        string user=i.substr(0,ind);
        string title=i.substr(ind+1);
        m_user[user]++;
        m_title[title]++;
    }
    int member=m_user.size();
    if(member%2)member=member/2+1;
    else member/=2;
    for(auto i:logs){
        int ind=i.find(' ');
        string user=i.substr(0,ind);
        string title=i.substr(ind+1);
        if(m_title[title]>=member)answer.push_back(title);
        m_title[title]=0;
    }
    sort(answer.begin(),answer.end());
    return answer;
}