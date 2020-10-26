#include <string>
#include <vector>

using namespace std;

/* 문제 - 이상한 문자 만들기 
문자열 s는 한 개 이상의 단어로 구성되어 있습니다. 
각 단어는 하나 이상의 공백문자로 구분되어 있습니다. 
각 단어의 짝수번째 알파벳은 대문자로, 홀수번째 알파벳은 
소문자로 바꾼 문자열을 리턴하는 함수, solution을 완성하세요.
*/

string solution(string s)
{
    string answer = "";
    int count = 1;
    int aski = 'A' - 'a';
    int size = s.size();

    for (int i = 0; i < size; i++)
    {
        if (s[i] == ' ')
        {
            answer += ' ';
            count = 1;
        }
        else if (count % 2 == 1)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                s[i] += aski;
                answer += s[i];
                count++;
            }
            else
            {
                answer += s[i];
                count++;
            }
        }
        else
        {
            if (s[i] >= 'a' && s[i] <= 'z')
            {

                answer += s[i];
                count++;
            }
            else
            {
                s[i] -= aski;
                answer += s[i];
                count++;
            }
        }
    }

    return answer;
}