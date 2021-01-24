#include <string>
#include <vector>
#include <iostream>

using namespace std;

/* 문제 124나라의 숫자 
124 나라가 있습니다. 124 나라에서는 10진법이 아닌 다음과 같은 자신들만의 규칙으로 수를 표현합니다.
124 나라에는 자연수만 존재합니다.
124 나라에는 모든 수를 표현할 때 1, 2, 4만 사용합니다.
예를 들어서 124 나라에서 사용하는 숫자는 다음과 같이 변환됩니다.
자연수 n이 매개변수로 주어질 때, n을 124 나라에서 사용하는 숫자로 바꾼 값을 
return 하도록 solution 함수를 완성해 주세요.
*/

string solution(int n)
{
    string answer = "";
    while (n != 0)
    {
        if (n % 3 == 0)
        {
            answer = '4' + answer;
            n = n / 3 - 1;
        }
        else if (n % 3 == 1)
        {
            answer = '1' + answer;
            n = n / 3;
        }
        else // n%3 == 2
        {
            answer = '2' + answer;
            n = n / 3;
        }
    }
    return answer;
}

int main(void)
{
    int n = 4;
    cout << "테스트 코드 실행 결과" << endl
         << solution(n);
    return 0;
}