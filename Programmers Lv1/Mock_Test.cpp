#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/* 문제 - 모의고사
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
    vector<int> one = {1, 2, 3, 4, 5};
    vector<int> two = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> three = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    vector<int> score = {0, 0, 0};

    int size = answers.size();
    for (int i = 0; i < size; i++)
    {
        if (answers[i] == one[i % one.size()])
        {
            score[0]++;
        }

        if (answers[i] == two[i % two.size()])
        {
            score[1]++;
        }

        if (answers[i] == three[i % three.size()])
        {
            score[2]++;
        }
    }

    int maxnum = *max_element(score.begin(), score.end());

    for (int i = 0; i < 3; i++)
    {
        if (maxnum == score[i])
            answer.push_back(i + 1);
    }

    return answer;
}

int main(void)
{
    vector<int> answers{1, 2, 3, 4, 5};
    cout << "테스트 코드 실행 결과" << endl;
    vector<int> result = solution(answers);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}