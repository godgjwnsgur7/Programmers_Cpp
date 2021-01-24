#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/* 문제 - 제일 작은 수 제거하기 
정수를 저장한 배열, arr 에서 가장 작은 수를 제거한 배열을 리턴하는 함수, 
solution을 완성해주세요. 단, 리턴하려는 배열이 빈 배열인 경우엔 배열에 -1을 채워 리턴하세요. 
예를들어 arr이 [4,3,2,1]인 경우는 [4,3,2]를 리턴 하고, [10]면 [-1]을 리턴 합니다.
*/

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    vector<int> arr2 = arr;
    sort(arr2.begin(), arr2.end());

    int size = arr.size();
    int min = arr2[0];

    for (int i = 0; i < size; i++)
    {
        if (min != arr[i])
        {
            answer.push_back(arr[i]);
        }
    }

    if (answer.size() == 0)
    {
        answer.push_back(-1);
    }

    return answer;
}

int main(void)
{
    vector<int> arr{4, 3, 2, 1};
    cout << "테스트 코드 실행 결과" << endl;
    vector<int> result = solution(arr);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}