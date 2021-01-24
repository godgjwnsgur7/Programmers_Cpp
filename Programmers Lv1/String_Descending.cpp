#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/* 문제 - 문자열 내림차순으로 배치 
문자열 s에 나타나는 문자를 큰것부터 작은 순으로 정렬해 
새로운 문자열을 리턴하는 함수, solution을 완성해주세요.
s는 영문 대소문자로만 구성되어 있으며, 대문자는 소문자보다 
작은 것으로 간주합니다.
*/

string solution(string s)
{
    string answer = "";
    sort(s.begin(), s.end(), greater<char>());

    answer = s;
    return answer;
}

int main(void)
{
    string s = "Zbcdefg";
    cout << "테스트 코드 실행 결과" << endl
         << solution(s);
    return 0;
}