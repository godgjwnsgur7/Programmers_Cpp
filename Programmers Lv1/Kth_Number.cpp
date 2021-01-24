#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/* 문제 - K번째 수
배열 array의 i번째 숫자부터 j번째 숫자까지 자르고 정렬했을 때,
k번째에 있는 수를 구하려 합니다.

예를 들어 array가 [1, 5, 2, 6, 3, 7, 4], i = 2, j = 5, k = 3이라면

array의 2번째부터 5번째까지 자르면 [5, 2, 6, 3]입니다.
1에서 나온 배열을 정렬하면 [2, 3, 5, 6]입니다.
2에서 나온 배열의 3번째 숫자는 5입니다.
배열 array, [i, j, k]를 원소로 가진 2차원 배열 commands가 매개변수로 주어질 때,
commands의 모든 원소에 대해 앞서 설명한 연산을 적용했을 때 나온 결과를
배열에 담아 return 하도록 solution 함수를 작성해주세요.

제한사항
array의 길이는 1 이상 100 이하입니다.
array의 각 원소는 1 이상 100 이하입니다.
commands의 길이는 1 이상 50 이하입니다.
commands의 각 원소는 길이가 3입니다.
*/

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
    vector<int> answer;

    vector<int> temarr;

    int size = commands.size(); // 2차원 배열 commands의 세로 길이

    int size2 = 0;

    int startnum, endnum, kth = 0;

    for (int i = 0; i < size; i++)
    {
        startnum = commands[i][0] - 1; // 자르기 시작점 startnum
        endnum = commands[i][1] - 1;   // 자르기 끝점 endnum
        kth = commands[i][2];          // 몇번째 ? kth

        for (int j = startnum; j <= endnum; j++)
        {
            temarr.push_back(array[j]);
        }

        if (temarr.size() == 1)
        {
            answer.push_back(temarr[0]);
        }
        else
        {
            sort(temarr.begin(), temarr.end());

            answer.push_back(temarr[kth - 1]);
        }

        temarr.clear();
    }
    return answer;
}

int main(void)
{
    vector<int> array{1, 5, 2, 6, 3, 7, 4};
    vector<vector<int>> commands{{2, 5, 3}, {4, 4, 1}, {1, 7, 3}};
    cout << "테스트 코드 실행 결과" << endl;
    vector<int> result = solution(array, commands);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}