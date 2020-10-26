#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/* 문제 - 삼각 달팽이 
삼각형 모양의 2차원 배열에 달팽이채우기를 하고,
첫 행부터 마지막 행까지 모두 순서대로 합친 새로운 배열을 return.
*/

vector<int> solution(int n)
{
    vector<int> answer;

    int ycount = n, xcount = n;
    int count = 1;
    int arrsize = 0;
    int totalcount = 0;

    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    } // 2차원 배열 동적할당

    for (int i = 0; i <= n; i++)
    {
        arrsize += i; // 결과적으로 출력할 배열의 크기
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 0; // 보기 편하게 모두 0으로 초기화하고 시작
        }
    }

    int x = 0, y = 0;

    while (count <= arrsize)
    {
        // 세로 이동
        while (y != ycount)
        {
            arr[y][x] = count;
            count++;
            y++;
            if (y == ycount)
            {
                x++;
            }
        }
        ycount--;
        y--;

        if (count > arrsize)
        {
            break; // 임시 조건확인
        }

        // 가로 이동
        while (x != xcount)
        {
            arr[y][x] = count;
            count++;
            x++;
        }
        xcount--;
        x--;
        totalcount++;

        if (count > arrsize)
        {
            break; // 임시 조건확인
        }

        // 대각 이동
        while (totalcount < x)
        {
            x--;
            y--;
            arr[y][x] = count;
            count++;
            if (totalcount == x)
            {
                y++;
            }
        }
        xcount--;
    }

    totalcount = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= totalcount; j++)
        {
            answer.push_back(arr[i][j]);
        }
        totalcount++;
    }

    // 동적할당 해제
    for (int i = 0; i < n; i++)
        delete[] arr[i];
    delete[] arr;

    return answer;
}