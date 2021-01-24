#include <iostream>
#include <string>
#include <iostream>

using namespace std;

/* 문제 - 자릿수 더하기 
자연수 N이 주어지면, N의 각 자릿수의 합을 구해서 return 하는 solution 함수를 만들어 주세요.
예를들어 N = 123이면 1 + 2 + 3 = 6을 return 하면 됩니다.
*/

int solution(int n)
{
    int answer = 0;
    string str = to_string(n);
    int size = str.size();
    int aski = '1' - 1;

    for (int i = 0; i < size; i++)
    {
        answer = answer + str[i] - aski;
    }

    return answer;
}

int main(void)
{
    int n = 123;
    cout << "테스트 코드 실행 결과" << endl
         << solution(n);
    return 0;
}