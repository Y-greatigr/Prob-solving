/*
īī���� �Ի��� ���� ������ �׿��� "īī������������"�� ��ġ�Ǿ�, īī�� ���񽺿� �����ϴ�
�������� ���̵� �����ϴ� ������ ����ϰ� �Ǿ����ϴ�. "�׿�"���� �־��� ù ������ ���� ����
�ϴ� �������� īī�� ���̵� ��Ģ�� ���� �ʴ� ���̵� �Է����� ��, �Էµ� ���̵�� �����ϸ鼭
��Ģ�� �´� ���̵� ��õ���ִ� ���α׷��� �����ϴ� ���Դϴ�.

������ īī�� �Ƶ���� ��Ģ�Դϴ�.
1. ���̵��� ���̴� 3�� �̻� 15�� ���Ͽ��� �մϴ�.
2. ���̵�� ���ĺ� �ҹ���, ����, ����(-), ����(_), ��ħǥ(.) ���ڸ� ����� �� �ֽ��ϴ�.
3. ��, ��ħǥ(.)�� ó���� ���� ����� �� ������ ���� �������� ����� �� �����ϴ�.

"�׿�"�� ������ ���� 7�ܰ��� �������� ó�� ������ ���� �ű� ������ �Է��� ���̵� īī�� ��
�̵� ��Ģ�� �´��� �˻��ϰ� ��Ģ�� ���� ���� ��� ��Ģ�� �´� ���ο� ���̵� ��õ�� �ַ���
�մϴ�.
�ű� ������ �Է��� ���̵� new_id ��� �Ѵٸ�,
1�ܰ� new_id�� ��� �빮�ڸ� �����Ǵ� �ҹ��ڷ� ġȯ�մϴ�.
2�ܰ� new_id���� ���ĺ� �ҹ���, ����, ����(-), ����(_), ��ħǥ(.) �� ������ ��� ���ڸ� �����մϴ�.
3�ܰ� new_id���� ��ħǥ(.)�� 2�� �̻� ���ӵ� �κ��� �ϳ��� ��ħǥ(.)�� ġȯ�մϴ�.
4�ܰ� new_id���� ��ħǥ(.) �� ó���̳� ���� ��ġ�Ѵٸ� �����մϴ�.
5�ܰ� new_id�� �� ���ڿ��̶��, new_id�� "a"�� �����մϴ�.
6�ܰ� new_id�� ���̰� 16�� �̻��̸�, new_id�� ù 15���� ���ڸ� ������ ������ ���ڵ��� �����մϴ�.
 ���� ���� �� ��ħǥ(.)�� new_id�� ���� ��ġ�Ѵٸ� ���� ��ġ�� ��ħǥ(.) ���ڸ� �����մϴ�.
7�ܰ� new_id�� ���̰� 2�� ���϶��, new_id�� ������ ���ڸ� new_id�� ���̰� 3�� �� ������ �ٿ��ݴϴ�.

���� �Է�1
new_id="...!@BaT#*..y.abcdefghijklm"

1�ܰ� �빮�� 'B'�� 'T'�� �ҹ��� 'b�� 't'�� �ٲ�����ϴ�.
"...!@BaT#*..y.abcdefghijklm" -> "...!@bat#*..y.abcdefghijklm"

2�ܰ� '!', '@', '#', '*' ���ڰ� ���ŵǾ����ϴ�.
"...!@bat#*..y.abcdefghijklm" -> "...bat..y.abcdefghijklm"

3�ܰ� '...'�� '..'�� '.'�� �ٲ�����ϴ�.
"...bat..y.abcdefghijklm" -> ".bat.y.abcdefghijklm"

4�ܰ� ���̵��� ó���� ��ġ�� '.'�� ���ŵǾ����ϴ�.
".bat.y.abcdefghijklm" -> "bat.y.abcdefghijklm"

5�ܰ� ���̵� �� ���ڿ��� �ƴϹǷ� ��ȭ�� �����ϴ�.
"bat.y.abcdefghijklm" -> "bat.y.abcdefghijklm"

6�ܰ� ���̵��� ���̰� 16�� �̻��̹Ƿ�, ó�� 15�ڸ� ������ ������ ���ڵ��� ���ŵǾ����ϴ�.
"bat.y.abcdefghijklm" -> "bat.y.abcdefghi"

7�ܰ� ���̵��� ���̰� 2�� ���ϰ� �ƴϹǷ� ��ȭ�� �����ϴ�.
"bat.y.abcdefghi" -> "bat.y.abcdefghi"

���� �ű� ������ �Է��� new_id�� "...!@BaT#*..y.abcdefghijklm" �� ��,
�׿��� ���α׷��� ��õ�ϴ� ���ο� ���̵�� "bat.y.abcdefghi" �Դϴ�.

����� ��2
"z-+.^." -> "z--"

����� ��3
"=.=" -> "aaa"

����� ��4
"123_.def" -> "123_.def"

����� ��5
"abcdefghijklmn.p" -> "abcdefghijklmn"
*/
#include<iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string new_id);
int main() {

    string id;
    for (int i = 0; i < 2; i++) {
        cin >> id;
        cout << solution(id) << endl << endl;
    }
    return 0;
}
string solution(string new_id) {
    string answer = "";
    char ch;
    for (int i = 0; i < new_id.length(); i++) { // 1�ܰ�, ��� �빮�ڸ� �����Ǵ� �ҹ��ڷ� ġȯ
        ch = new_id[i];
        if (ch >= 'A' && ch <= 'Z')
            answer += ch - 'A' + 'a';
        else
            answer += ch;
    }

    for (int i = 0; i < answer.length(); i++) { // 2�ܰ�, ���ĺ� �ҹ���, ����, ����(-), ����(_), ��ħǥ(.) �� ������ ��� ���ڸ� ����
        ch = answer[i];
        if (('0' > ch || ch > '9') && ('a' > ch || ch > 'z') && ch != '-' && ch != '_' && ch != '.') {
            answer.erase(i, 1);
            i--;
        }
    }

    for (int i = 0; i < answer.length(); i++) { // 3�ܰ�, ��ħǥ(.)�� 2�� �̻� ���ӵ� �κ��� �ϳ��� ��ħǥ(.)�� ġȯ
        int a = i + 1;
        if (answer[i] == '.')
            if (answer[a] == '.') {
                answer.erase(i, 1);
                i--;
            }
    }

    if (answer[0] == '.') // 4�ܰ�, ��ħǥ(.) �� ó���̳� ���� ��ġ�Ѵٸ� ����
        answer.erase(0, 1);
    if(answer.length()>0)
        if (answer[answer.length() - 1] == '.')
            answer.erase(answer.length() - 1, 1);

    if (answer == "") // 5�ܰ�, �� ���ڿ��̶��, new_id�� "a"�� ����
        answer.append("a");

    for (int i = 0; i < answer.length(); i++) { // 6�ܰ�, ���̰� 16�� �̻��̸�, new_id�� ù 15���� ���ڸ� ������ ������ ���ڵ��� ����
        if(i==15)
            answer.erase(15);
    }
    if(answer[answer.length()-1]=='.') //  ���� ���� �� ��ħǥ(.)�� new_id�� ���� ��ġ�Ѵٸ� ���� ��ġ�� ��ħǥ(.) ���ڸ� ����
        answer.erase(answer.length() - 1);

    if (answer.size() < 3) // 7�ܰ�, new_id�� ���̰� 2�� ���϶��, new_id�� ������ ���ڸ� new_id�� ���̰� 3�� �� ������ ����
        ch = answer[answer.length() - 1];
        for(int i=0;answer.size()<3;i++)
            answer=answer+ch;
    return answer;
}