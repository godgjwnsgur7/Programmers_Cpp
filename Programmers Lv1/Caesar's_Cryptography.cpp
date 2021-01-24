#include <string>
#include <vector>
#include <iostream>

using namespace std;

/* 문제 - 시저 암호 
어떤 문장의 각 알파벳을 일정한 거리만큼 밀어서 다른 알파벳으로 바꾸는 
암호화 방식을 시저 암호라고 합니다. 
예를 들어 AB는 1만큼 밀면 BC가 되고, 3만큼 밀면 DE가 됩니다. 
z는 1만큼 밀면 a가 됩니다. 문자열 s와 거리 n을 입력받아 s를 n만큼 
민 암호문을 만드는 함수, solution을 완성해 보세요.
*/

string solution(string s, int n)
{
    string answer = "";

    int size = s.size();

    int aski = 'z' - 'a';

    for (int i = 0; i < size; i++) // 각 요소에 접근합니다.
    {
        if (s[i] != ' ')
        {
            for (int j = 0; j < n; j++)
            {
                if (s[i] == 'z' || s[i] == 'Z')
                {
                    s[i] -= aski;
                }
                else
                {
                    s[i] += 1;
                }
            }
        }
    }

    answer = s;

    return answer;
}

int main(void)
{
    string s = "AB";
    int n = 1;
    cout
        << "테스트 코드 실행 결과" << endl
        << solution(s, n);
    return 0;
}