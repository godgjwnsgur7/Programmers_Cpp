#include <string>
#include <vector>

using namespace std;

/* 문제 - 스킬트리
선행 스킬이란 어떤 스킬을 배우기 전에 먼저 배워야 하는 스킬을 뜻합니다.
예를 들어 선행 스킬 순서가 스파크 → 라이트닝 볼트 → 썬더일때,
썬더를 배우려면 먼저 라이트닝 볼트를 배워야 하고, 라이트닝 볼트를 배우려면 먼저 스파크를 배워야 합니다.
위 순서에 없는 다른 스킬(힐링 등)은 순서에 상관없이 배울 수 있습니다.
따라서 스파크 → 힐링 → 라이트닝 볼트 → 썬더와 같은 스킬트리는 가능하지만,
썬더 → 스파크나 라이트닝 볼트 → 스파크 → 힐링 → 썬더와 같은 스킬트리는 불가능합니다.

선행 스킬 순서 skill과 유저들이 만든 스킬트리1를 담은 배열 skill_trees가 매개변수로 주어질 때,
가능한 스킬트리 개수를 return 하는 solution 함수를 작성해주세요.

*/

int solution(string skill, vector<string> skill_trees)
{
    int answer = 0;

    for (int i = 0; i < skill_trees.size(); i++)
    {
        vector<int> temp;
        // temp에 스킬트리로 주어진 것만 넣기
        for (int j = 0; j < skill_trees[i].size(); j++)
        {
            for (int k = 0; k < skill.size(); k++)
            {
                if (skill[k] == skill_trees[i][j])
                {
                    temp.push_back(skill_trees[i][j]);
                }
            }
        }
        // temp의 순서가 skill과 맞는지 확인
        int flag = 0;
        for (int j = 0; j < temp.size(); j++)
        {
            if (temp[j] != skill[j])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            answer++;
        }
    }
    return answer;
}