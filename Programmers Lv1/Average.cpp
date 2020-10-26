#include <string>
#include <vector>

using namespace std;

/* 문제 - 평균 구하기 
정수를 담고 있는 배열 arr의 평균값을 return하는 함수, solution을 완성해보세요.
*/

double solution(vector<int> arr)
{
    int size = arr.size();
    double answer = 0;
    double total = 0;

    for (int i = 0; i < size; i++)
    {
        total += arr[i];
    }

    answer = total / size;

    return answer;
}