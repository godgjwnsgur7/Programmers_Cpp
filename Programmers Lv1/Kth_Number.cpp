#include <string>
#include <vector>
#include <algorithm>

using namespace std;

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