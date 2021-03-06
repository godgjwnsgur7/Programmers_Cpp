#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

/* 문제 - 정수 제곱근 판별 
임의의 양의 정수 n에 대해, n이 어떤 양의 정수 x의 제곱인지 아닌지 판단하려 합니다.
n이 양의 정수 x의 제곱이라면 x+1의 제곱을 리턴하고, 
n이 양의 정수 x의 제곱이 아니라면 -1을 리턴하는 함수를 완성하세요.
*/

long long solution(long long n)
{
    long long answer = 0;

    long double a = sqrt(n);
    long long b = sqrt(n);

    if (a == b)
    {
        answer = (a + 1) * (a + 1);
    }
    else
    {
        return -1;
    }

    return answer;
}

int main(void)
{
    long long n = 121;
    cout << "테스트 코드 실행 결과" << endl
         << solution(n);
    return 0;
}