#include <iostream>
#include <string>
#include <vector>

using namespace std;

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