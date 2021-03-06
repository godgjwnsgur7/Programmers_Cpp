#include <string>
#include <vector>
#include <iostream>

using namespace std;

/* 문제 - 서울에서 김서방 찾기 
String형 배열 seoul의 element중 Kim의 위치 x를 찾아, 
김서방은 x에 있다는 String을 반환하는 함수, solution을 완성하세요. 
seoul에 Kim은 오직 한 번만 나타나며 잘못된 값이 입력되는 경우는 없습니다.
*/

string solution(vector<string> seoul)
{
    string answer = "";
    int count = 0;
    int size = seoul.size();

    for (int i = 0; i < size; i++)
    {
        if (seoul[i] == "Kim")
        {
            count = i;
            break;
        }
    }

    answer = "김서방은 " + to_string(count) + "에 있다";

    return answer;
}

int main(void)
{
    vector<string> seoul{"Jane", "Kim"};
    cout << "테스트 코드 실행 결과" << endl
         << solution(seoul);
    return 0;
}