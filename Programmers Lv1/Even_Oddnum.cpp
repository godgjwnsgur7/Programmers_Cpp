#include <string>
#include <vector>
#include <iostream>

using namespace std;

/* 문제 - 짝수와 홀수 
정수 num이 짝수일 경우 Even을 반환하고 홀수인 경우 Odd를 반환하는 함수, solution을 완성해주세요.
*/

string solution(int num)
{
    string answer = "";

    if (num % 2 != 0)
    {
        answer += "Odd";
    }
    else
    {
        answer += "Even";
    }

    return answer;
}

int main(void)
{
    int num = 3;
    cout << "테스트 코드 실행 결과" << endl
         << solution(num);
    return 0;
}