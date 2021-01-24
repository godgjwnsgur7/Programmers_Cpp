#include <string>
#include <vector>
#include <iostream>

using namespace std;

/* 문제 - 문자열을 정수로 바꾸기 
문자열 s를 숫자로 변환한 결과를 반환하는 함수, solution을 완성하세요.
*/

int solution(string s)
{
    int answer = atoi(s.c_str());

    return answer;
}

int main(void)
{
    string s = "1234";
    cout << "테스트 코드 실행 결과" << endl
         << solution(s);
    return 0;
}