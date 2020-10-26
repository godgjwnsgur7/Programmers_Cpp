#include <string>
#include <vector>

using namespace std;

/* 문제 - 3진법 뒤집기 
자연수 n이 매개변수로 주어집니다. n을 3진법 상에서 앞뒤로 뒤집은 후, 
이를 다시 10진법으로 표현한 수를 return 하도록 solution 함수를 완성해주세요.
*/

int solution(int n)
{
    int answer = 0;
    int num = 1;
    vector<int> arr;

    while (n != 0) // 3진법 변환
    {
        arr.push_back(n % 3);
        n /= 3;
    }

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        answer = answer + arr[i] * num;
        num *= 3;
    }

    return answer;
}