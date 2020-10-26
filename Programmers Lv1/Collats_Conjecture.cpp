#include <string>
#include <vector>

using namespace std;

/* 문제 - 콜라츠 추측 
1937년 Collatz란 사람에 의해 제기된 이 추측은, 
주어진 수가 1이 될때까지 다음 작업을 반복하면, 
모든 수를 1로 만들 수 있다는 추측입니다.
*/

int solution(int num)
{
    int answer = 0;

    while (answer < 480)
    {
        if (num == 1)
        {
            return answer;
        }
        else if (num % 2 == 0)
        {
            num /= 2;
            answer++;
        }
        else
        {
            num = num * 3 + 1;
            answer++;
        }
    }

    return -1;
}