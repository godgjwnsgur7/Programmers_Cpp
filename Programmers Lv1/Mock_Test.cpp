#include <string>
#include <vector>

using namespace std;

/* 문제 - 
수포자는 수학을 포기한 사람의 준말입니다. 수포자 삼인방은 모의고사에 수학 문제를 전부 찍으려 합니다. 
수포자는 1번 문제부터 마지막 문제까지 다음과 같이 찍습니다.

1번 수포자가 찍는 방식: 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, ...
2번 수포자가 찍는 방식: 2, 1, 2, 3, 2, 4, 2, 5, 2, 1, 2, 3, 2, 4, 2, 5, ...
3번 수포자가 찍는 방식: 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, ...

1번 문제부터 마지막 문제까지의 정답이 순서대로 들은 배열 answers가 주어졌을 때,
가장 많은 문제를 맞힌 사람이 누구인지 배열에 담아 return 하도록 solution 함수를 작성해주세요.
*/

vector<int> solution(vector<int> answers)
{
    vector<int> answer;
    int one[] = {1, 2, 3, 4, 5};
    int two[] = {2, 1, 2, 3, 2, 4, 2, 5};
    int three[] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    int score[3] = {0};

    int size = answers.size();
    for (int i = 0; i < size; i++)
    {
        if (answers[i] == one[i % 5])
        {
            score[0]++;
        }

        if (answers[i] == two[i % 8])
        {
            score[1]++;
        }

        if (answers[i] == three[i % 10])
        {
            score[2]++;
        }
    }

    int max = score[0];
    if (max <= score[1])
        max = score[1];
    if (max <= score[2])
        max = score[2];

    for (int i = 0; i < 3; i++)
    {
        if (max == score[i])
            answer.push_back(i + 1);
    }

    return answer;
}