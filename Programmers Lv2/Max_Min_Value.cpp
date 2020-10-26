#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/* 문제 - 최댓값과 최솟값 
문자열 s에는 공백으로 구분된 숫자들이 저장되어 있습니다. 
str에 나타나는 숫자 중 최소값과 최대값을 찾아 이를 (최소값) (최대값)형태의 
문자열을 반환하는 함수, solution을 완성하세요.
예를들어 s가 1 2 3 4라면 1 4를 리턴하고, -1 -2 -3 -4라면 -4 -1을 리턴하면 됩니다.
*/

string solution(string s)
{
    string answer = "";
    string tmp;
    vector<int> arr;
    int size = s.size();

    for (int i = 0; i < size; i++)
    {
        if (s[i] == ' ')
        {
            arr.push_back(atoi(tmp.c_str()));
            tmp.clear();
        }
        else
        {
            tmp += s[i];
        }
    }

    arr.push_back(atoi(tmp.c_str()));
    sort(arr.begin(), arr.end());
    answer += to_string(arr.front()) + ' ' + to_string(arr.back());

    return answer;
}