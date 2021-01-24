#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* 문제 - 수박수박수박수박수? 
길이가 n이고, 수박수박수박수....와 같은 패턴을 유지하는 문자열을 리턴하는 함수, 
solution을 완성하세요. 예를들어 n이 4이면 수박수박을 리턴하고 3이라면 
수박수를 리턴하면 됩니다.
*/

string solution(int n)
{
    string answer = "";

    if (n >= 1)
    {
        answer += "수";
    }

    for (int i = 1; i < n; i++)
    {
        if (i % 2 == 1)
        {
            answer += "박";
        }
        else
        {
            answer += "수";
        }
    }

    return answer;
}

int main(void)
{
    int n = 3;
    cout << "테스트 코드 실행 결과" << endl
         << solution(n);
    return 0;
}