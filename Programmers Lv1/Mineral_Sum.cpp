#include <string>
#include <iostream>
#include <vector>

using namespace std;

/* 문제 - 약수의 합 
정수 n을 입력받아 n의 약수를 모두 더한 값을 리턴하는 함수, solution을 완성해주세요.
*/

int solution(int n)
{
    int answer = 0;

    answer = n;

    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
        {
            answer += i;
        }
    }

    return answer;
}

int main(void)
{
    int n = 12;
    cout << "테스트 코드 실행 결과" << endl
         << solution(n);
    return 0;
}