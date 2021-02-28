#include <string>
#include <vector>
#include <iostream>

using namespace std;

/* 문제 - 숫자의 표현
자연수 n이 매개변수로 주어질 때,
연속된 자연수들로 n을 표현하는 방법의 수를 return하는 solution를 완성해주세요.
제한 조건
n은 10,000 이하의 자연수 입니다.
*/

int solution(int n)
{
    int answer = 0;
    int num = 1;
    while (num <= n)
    {
        int temNum = 0;
        for (int i = num; i <= n; i++)
        {
            temNum += i;

            if (temNum > n)
                i = n + 1;

            if (temNum == n)
                answer++;
        }
        num++;
    }
    return answer;
}

int main(void)
{
    int n = 15;
    cout << "테스트 코드 실행 결과" << endl
         << solution(n);
    return 0;
}