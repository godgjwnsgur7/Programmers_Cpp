#include <iostream>
#include <cstdlib>
using namespace std;

class BoundCheckIntArray
{
private:
    int *arr;
    int arrlen;
    BoundCheckIntArray(const BoundCheckIntArray &arr) {}
    BoundCheckIntArray &operator=(const BoundCheckIntArray &arr) {}

public:
    BoundCheckIntArray(int len) : arrlen(len)
    {
        arr = new int[len];
    }

    int &operator[](int idx)
    {
        if (idx < 0 || idx >= arrlen)
        {
            cout << "범위를 벗어남" << endl;
            exit(1);
        }
        return arr[idx];
    }

    int operator[](int idx) const
    {
        if (idx < 0 || idx >= arrlen)
        {
            cout << "범위를 벗어남" << endl;
            exit(1);
        }
        return arr[idx];
    }

    int GetArrLen() const
    {
        return arrlen;
    }

    ~BoundCheckIntArray()
    {
        delete[] arr;
    }
};

typedef BoundCheckIntArray *BoundCheckIntArrayPtr; // 포인터 자료형 선언

class BoundCheck2DIntArray
{
private:
    BoundCheckIntArray **arr; // 더블포인터 배열 arr
    int arrlen;
    BoundCheck2DIntArray(const BoundCheck2DIntArray &arr) {}
    BoundCheck2DIntArray &operator=(const BoundCheck2DIntArray &arr) {}

public:
    BoundCheck2DIntArray(int col, int row) : arrlen(col) // 2차원 배열을 한줄씩 초기화하는 생성자
    {
        arr = new BoundCheckIntArrayPtr[col];
        for (int i = 0; i < col; i++)
            arr[i] = new BoundCheckIntArray(row);
    }

    BoundCheckIntArray &operator[](int idx)
    {
        if (idx < 0 || idx >= arrlen)
        {
            cout << "범위를 벗어남" << endl;
            exit(1);
        }
        return *(arr[idx]);
    }

    ~BoundCheck2DIntArray()
    {
        for (int i = 0; i << arrlen; i++)
            delete arr[i];
        delete[] arr;
    }
};

int main(void)
{
    BoundCheck2DIntArray arr2d(5, 5);
    int i = 5;
    int j = 5;
    for (int n = 0; n < i; n++)
        for (int m = 0; m < j; m++)
            arr2d[n][m] = n + m;
    for (int n = 0; n < i; n++)
    {
        for (int m = 0; m < j; m++)
            cout << arr2d[n][m] << ' ';
        cout << endl;
    }
    return 0;
}
