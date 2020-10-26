#include <string>
#include <vector>

using namespace std;

/* 문제 - 가운데 글자 가져오기 
단어 s의 가운데 글자를 반환하는 함수, solution을 만들어 보세요. 
단어의 길이가 짝수라면 가운데 두글자를 반환하면 됩니다.
*/

string solution(string s)
{
    string answer = "";
    int size = s.size();

    if (size % 2 == 0)
    {
        answer += s[size / 2 - 1];
        answer += s[size / 2];
    }
    else
    {
        answer += s[(size - 1) / 2];
    }

    return answer;
}