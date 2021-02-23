#include <string>
#include <vector>
#include <iostream>

using namespace std;

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