#include <iostream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* 문제 - 최솟값 만들기
길이가 같은 배열 A, B 두개가 있습니다. 각 배열은 자연수로 이루어져 있습니다.
배열 A, B에서 각각 한 개의 숫자를 뽑아 두 수를 곱합니다.
이러한 과정을 배열의 길이만큼 반복하며, 두 수를 곱한 값을 누적하여 더합니다.
이때 최종적으로 누적된 값이 최소가 되도록 만드는 것이 목표입니다.
(단, 각 배열에서 k번째 숫자를 뽑았다면 다음에 k번째 숫자는 다시 뽑을 수 없습니다.)

제한사항
배열 A, B의 크기 : 1,000 이하의 자연수
배열 A, B의 원소의 크기 : 1,000 이하의 자연수
*/

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;

    sort(A.begin(), A.end());
    sort(B.rbegin(), B.rend());

    for (int i = 0; i < A.size(); i++)
    {
        answer += A[i] * B[i];
    }

    return answer;
}

int main(void)
{
    vector<int> A{1, 4, 2};
    vector<int> B{5, 4, 4};
    cout << "테스트 코드 실행 결과" << endl
         << solution(A, B);
    return 0;
}