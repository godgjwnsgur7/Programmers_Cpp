#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* 문제 - 문자열 다루기 기본 
문자열 s의 길이가 4 혹은 6이고, 숫자로만 구성돼있는지 확인해주는 함수, 
solution을 완성하세요. 예를 들어 s가 a234이면 False를 리턴하고 
1234라면 True를 리턴하면 됩니다.
*/

bool solution(string s)
{
    bool answer = true;
    int size = s.size();

    if (size != 4 && size != 6)
    {
        answer = false;
    }

    for (int i = 0; i < size; i++)
    {
        if (48 <= s[i] && s[i] <= 57)
        {
        }
        else
        {
            answer = false;
        }
    }

    return answer;
}

int main(void)
{
    string s = "a234";
    cout << "테스트 코드 실행 결과" << endl
         << solution(s);
    return 0;
}