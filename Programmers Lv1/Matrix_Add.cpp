#include <string>
#include <vector>
#include <iostream>

using namespace std;

/* 문제 - 행렬의 덧셈
행렬의 덧셈은 행과 열의 크기가 같은 두 행렬의 같은 행, 같은 열의 값을 서로 더한 결과가 됩니다. 2개의 행렬 arr1과 arr2를 입력받아, 행렬 덧셈의 결과를 반환하는 함수, solution을 완성해주세요.

제한 조건
행렬 arr1, arr2의 행과 열의 길이는 500을 넘지 않습니다.
*/

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2)
{
    vector<vector<int>> answer;

    for (int i = 0; i < arr1.size(); i++)
    {
        vector<int> temArr;

        for (int j = 0; j < arr1[0].size(); j++)
        {
            temArr.push_back(arr1[i][j] + arr2[i][j]);
        }
        answer.push_back(temArr);
    }

    return answer;
}

int main(void)
{
    vector<vector<int>> arr1{{1, 2}, {3, 2}};
    vector<vector<int>> arr2{{3, 2}, {1, 2}};
    cout << "테스트 코드 실행 결과" << endl;
    vector<vector<int>> result = solution(arr1, arr2);
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[0].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}