#include <string>
#include <iostream>
using namespace std;

/* 문제 - 문자열 내 p와 y의 개수 
대문자와 소문자가 섞여있는 문자열 s가 주어집니다. 
s에 'p'의 개수와 'y'의 개수를 비교해 같으면 True, 
다르면 False를 return 하는 solution를 완성하세요. 
'p', 'y' 모두 하나도 없는 경우는 항상 True를 리턴합니다. 
단, 개수를 비교할 때 대문자와 소문자는 구별하지 않습니다.
예를 들어 s가 pPoooyY면 true를 return하고 Pyy라면 false를 return합니다.
*/

bool solution(string s)
{
    bool answer = true;
    int size = s.length();
    int pCount = 0, yCount = 0;

    for (int i = 0; i < size; i++)
    {
        if (s[i] == 'p' || s[i] == 'P')
        {
            pCount++;
        }
        else if (s[i] == 'y' || s[i] == 'Y')
        {
            yCount++;
        }
    }

    if (pCount != yCount)
    {
        answer = false;
    }

    return answer;
}

int main(void)
{
    string s = "pPoooyY";
    cout << "테스트 코드 실행 결과" << endl
         << solution(s);
    return 0;
}