#include <string>
#include <vector>
#include <iostream>

using namespace std;

/* 문제 - 이진 변환 반복하기
0과 1로 이루어진 어떤 문자열 x에 대한 이진 변환을 다음과 같이 정의합니다.
1. x의 모든 0을 제거합니다.
2. x의 길이를 c라고 하면, x를 c를 2진법으로 표현한 문자열로 바꿉니다.
예를 들어, x = "0111010"이라면, x에 이진 변환을 가하면 x = "0111010" -> "1111" -> "100" 이 됩니다.
0과 1로 이루어진 문자열 s가 매개변수로 주어집니다. s가 1이 될 때까지 계속해서 s에 이진 변환을 가했을 때,
이진 변환의 횟수와 변환 과정에서 제거된 모든 0의 개수를 각각 배열에 담아 return 하도록 solution 함수를 완성해주세요.
*/

vector<int> solution(string s)
{
    vector<int> answer{0, 0};

    while (s != "1")
    {
        int num = 0;
        string temStr = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '0')
                answer[1]++;
            else
                temStr += "1";
        }
        num = temStr.size();
        s = "";
        while (num > 0)
        {
            s += to_string(num % 2);
            num /= 2;
        }
        answer[0]++;
    }
    return answer;
}

int main(void)
{
    string s = "110010101001";
    cout << "테스트 코드 실행 결과" << endl;
    vector<int> result = solution(s);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}