#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/* 문제 - 두 개 뽑아서 더하기 
정수 배열 numbers가 주어집니다. numbers에서 서로 다른 인덱스에 있는 두 개의 
수를 뽑아 더해서 만들 수 있는 모든 수를 배열에 오름차순으로 담아 return 하도록 
solution 함수를 완성해주세요.
*/

vector<int> solution(vector<int> numbers)
{
    vector<int> answer;

    int size = numbers.size();

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i != j)
            {
                answer.push_back(numbers[i] + numbers[j]);
            }
        }
    }

    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());

    return answer;
}