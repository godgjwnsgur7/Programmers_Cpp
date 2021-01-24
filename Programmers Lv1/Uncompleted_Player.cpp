#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/* 문제 - 완주하지 못한 선수 
수많은 마라톤 선수들이 마라톤에 참여하였습니다.
단 한 명의 선수를 제외하고는 모든 선수가 마라톤을 완주하였습니다.
마라톤에 참여한 선수들의 이름이 담긴 배열 participant와 
완주한 선수들의 이름이 담긴 배열 completion이 주어질 때, 
완주하지 못한 선수의 이름을 return 하도록 solution 함수를 작성해주세요.
*/

string solution(vector<string> participant, vector<string> completion)
{
    string answer = "";

    sort(participant.begin(), participant.end());

    sort(completion.begin(), completion.end());

    int size = participant.size();

    completion.push_back("a1s2d3");

    for (int i = 0; i < size; i++)
    {
        if (participant[i] != completion[i])
        {
            answer = participant[i];
            break;
        }
    }

    return answer;
}

int main(void)
{
    vector<string> partcipant{"leo", "kiki", "eden"};
    vector<string> completion{"eden", "kiki"};
    cout << "테스트 코드 실행 결과" << endl
         << solution(partcipant, completion);
    return 0;
}