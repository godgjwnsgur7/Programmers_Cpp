#include <string>
#include <vector>

using namespace std;

/* 문제 - 영어 끝말잇기
1부터 n까지 번호가 붙어있는 n명의 사람이 영어 끝말잇기를 하고 있습니다.
영어 끝말잇기는 다음과 같은 규칙으로 진행됩니다.
1. 1번부터 번호 순서대로 한 사람씩 차례대로 단어를 말합니다.
2. 마지막 사람이 단어를 말한 다음에는 다시 1번부터 시작합니다.
3. 앞사람이 말한 단어의 마지막 문자로 시작하는 단어를 말해야 합니다.
4. 이전에 등장했던 단어는 사용할 수 없습니다.
5. 한 글자인 단어는 인정되지 않습니다
[번호, 차례]로 출력
*/

vector<int> solution(int n, vector<string> words)
{
    vector<int> answer;
    int chack = 0;
    int number = 0;
    int turn = 0;

    for (int i = 1; i < words.size(); i++)
    {
        string str1 = words[i - 1];
        string str2 = words[i];

        for (int j = 0; j < i; j++)
        {
            if (words[j] == words[i])
            {
                chack = 1;
                break;
            }
        }

        int len_str1 = str1.length();

        if (str1[len_str1 - 1] != str2[0])
            chack = 1;

        if (chack)
        {
            number = (i % n) + 1;
            turn = (i / n) + 1;
            answer.push_back(number);
            answer.push_back(turn);
            return answer;
        }
    }
    answer.push_back(0);
    answer.push_back(0);
    return answer;
}