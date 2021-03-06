#include <iostream>
#include <string>
#include <stack>
using namespace std;

/* 문제 - 짝 지어 제거하기
짝지어 제거하기는, 알파벳 소문자로 이루어진 문자열을 가지고 시작합니다. 먼저 문자열에서 같은 알파벳이 2개 붙어 있는 짝을 찾습니다.
그다음, 그 둘을 제거한 뒤, 앞뒤로 문자열을 이어 붙입니다. 이 과정을 반복해서 문자열을 모두 제거한다면 짝지어 제거하기가 종료됩니다.
문자열 S가 주어졌을 때, 짝지어 제거하기를 성공적으로 수행할 수 있는지 반환하는 함수를 완성해 주세요.
성공적으로 수행할 수 있으면 1을, 아닐 경우 0을 리턴해주면 됩니다.
예를 들어, 문자열 S = baabaa 라면 b aa baa → bb aa → aa →
의 순서로 문자열을 모두 제거할 수 있으므로 1을 반환합니다.
*/

int solution(string s)
{
    int answer = 0;
    stack<char> sta_str;

    for (int i = 0; i < s.size(); i++)
    {
        // else 경우를 제외한 나머지엔 s[i]를 push
        if (sta_str.empty() || sta_str.top() != s[i])
        {
            sta_str.push(s[i]);
        }
        // 스택 top 값 == s[i] => top값 pop
        else
        {
            sta_str.pop();
        }
    }

    // 스택이 비어있다면 모든 문자열 제거 가능
    if (sta_str.empty())
    {
        answer = 1;
    }
    return answer;
}

int main(void)
{
    string s = "baabaa";
    cout << "테스트 코드 실행 결과" << endl
         << solution(s);
    return 0;
}