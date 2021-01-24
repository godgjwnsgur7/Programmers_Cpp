#include <iostream>
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
    int i, j;
    for (i = 1; i < words.size(); i++)
    {
        if (words[i - 1][words[i - 1].size() - 1] != words[i][0])
            break;
        for (j = 0; j < i; j++)
        {
            if (words[j].compare(words[i]) == 0)
                break;
        }
        if (j != i)
            break;
    }
    if (i == words.size())
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else
    {
        answer.push_back(i % n + 1);
        answer.push_back(i / n + 1);
    }
    return answer;
}

int main(void)
{
    int n = 3;
    vector<string> words{"tank, kick, know, wheel, land, dream, mother, robot, tank"};
    cout << "테스트 코드 실행 결과" << endl;
    vector<int> result = solution(n, words);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}