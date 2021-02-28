#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* 문제 - 행렬의 곱셈
2차원 행렬 arr1과 arr2를 입력받아, arr1에 arr2를 곱한 결과를 반환하는 함수, solution을 완성해주세요.
제한 조건
행렬 arr1, arr2의 행과 열의 길이는 2 이상 100 이하입니다.
행렬 arr1, arr2의 원소는 -10 이상 20 이하인 자연수입니다.
곱할 수 있는 배열만 주어집니다.
*/

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2)
{
    vector<vector<int>> answer;

    for (int i = 0; i < arr1.size(); i++) // arr1 세로 사이즈
    {
        vector<int> temp;
        for (int j = 0; j < arr2[0].size(); j++) // arr2 가로 사이즈
        {
            int total = 0;
            for (int k = 0; k < arr1[0].size(); k++) // arr1 가로 사이즈
            {
                total += arr1[i][k] * arr2[k][j];
            }
            temp.push_back(total);
        }
        answer.push_back(temp);
    }

    return answer;
}

int main(void)
{
    vector<vector<int>> arr1{{1, 4}, {3, 2}, {4, 1}};
    vector<vector<int>> arr2{{3, 3}, {3, 3}};
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