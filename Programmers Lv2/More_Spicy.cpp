#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

/* 문제 - 더 맵게
모든 음식의 스코빌 지수를 K 이상으로 만들기 위해
Leo는 스코빌 지수가 가장 낮은 두 개의 음식을 아래와 같이 특별한 방법으로 섞어 새로운 음식을 만듭니다.
섞은 음식의 스코빌 지수 = 가장 맵지 않은 음식의 스코빌 지수 + (두 번째로 맵지 않은 음식의 스코빌 지수 * 2)
Leo가 가진 음식의 스코빌 지수를 담은 배열 scoville과 원하는 스코빌 지수 K가 주어질 때, 
모든 음식의 스코빌 지수를 K 이상으로 만들기 위해 섞어야 하는 최소 횟수를 return 하도록 solution 함수를 작성해주세요.

제한 사항
scoville의 길이는 2 이상 1,000,000 이하입니다.
K는 0 이상 1,000,000,000 이하입니다.
scoville의 원소는 각각 0 이상 1,000,000 이하입니다.
모든 음식의 스코빌 지수를 K 이상으로 만들 수 없는 경우에는 -1을 return 합니다
*/

int solution(vector<int> scoville, int K)
{
    int answer = 0;
    int num1, num2;
    if (scoville.size() == 1)
    {
        if (scoville[0] < K)
            return -1;
        else
            return 0;
    }
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < scoville.size(); i++)
    {
        q.push(scoville[i]);
    }
    while (q.top() < K && q.size() > 1)
    {
        num1 = q.top();
        q.pop();
        num2 = q.top();
        q.pop();
        q.push(num1 + num2 * 2);
        answer++;
    }
    if (q.top() < K)
        return -1;
    return answer;
}

int main(void)
{
    vector<int> scoville{1, 2, 3, 9, 10, 12};
    int K = 7;
    cout << "테스트 코드 실행 결과" << endl;
    cout << solution(scoville, K);
    return 0;
}