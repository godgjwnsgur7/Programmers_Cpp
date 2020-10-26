#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/* 문제 - 자연수 뒤집어 배열로 만들기 
자연수 n을 뒤집어 각 자리 숫자를 원소로 가지는 배열 형태로 리턴해주세요. 
예를들어 n이 12345이면 [5,4,3,2,1]을 리턴합니다.
*/

vector<int> solution(long long n)
{
    vector<int> answer;

    string str = to_string(n);
    int aski = '1' - 1;
    int size = str.size();

    for (int i = size - 1; i >= 0; i--)
    {
        str[i] -= aski;
        answer.push_back(str[i]);
    }

    return answer;
}