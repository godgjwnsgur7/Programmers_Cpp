#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* 문제 - 땅따먹기
땅따먹기 게임을 하려고 합니다.
땅따먹기 게임의 땅(land)은 총 N행 4열로 이루어져 있고,
모든 칸에는 점수가 쓰여 있습니다. 1행부터 땅을 밟으며 한 행씩 내려올 때,
각 행의 4칸 중 한 칸만 밟으면서 내려와야 합니다. 단, 땅따먹기 게임에는 한 행씩 내려올 때,
같은 열을 연속해서 밟을 수 없는 특수 규칙이 있습니다.

제한 조건
행의 개수 N : 100,000 이하의 자연수
열의 개수는 4개이고, 땅(land)은 2차원 배열로 주어집니다.
점수 : 100 이하의 자연수
*/

int Max_Check(vector<int> &_land, int _index)
{
    int pos = 0;
    for (int i = 0; i < 4; i++)
        if (i != _index)
            pos = max(pos, _land[i]);
    return pos;
}

int solution(vector<vector<int>> land)
{
    int answer = 0;
    for (int i = 1; i < land.size(); i++)
    {
        for (int j = 0; j < 4; j++)
        {
            land[i][j] += Max_Check(land[i - 1], j);
            answer = max(land[i][j], answer);
        }
    }
    return answer;
}

int main(void)
{
    vector<vector<int>> land{{1, 2, 3, 5}, {5, 6, 7, 8}, {4, 3, 2, 1}};
    cout << "테스트 코드 실행 결과" << endl;
    cout << solution(land);
    return 0;
}