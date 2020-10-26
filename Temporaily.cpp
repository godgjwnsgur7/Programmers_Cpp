#include <iostream>
using namespace std;

class SoSimple
{
private:
    int num;

public:
    SoSimple(int n) : num(n)
    {
        cout << "New Object: " << this << " 생성자" << endl;
    }
    SoSimple(const SoSimple &copy) : num(copy.num)
    {
        cout << "New Copy obj: " << this << " 복사생성자" << endl;
    }
    ~SoSimple()
    {
        cout << "Destroy obj: " << this << " 소멸자" << endl;
    }
};

SoSimple SimpleFuncObj(SoSimple ob)
{
    cout << "Parm ADR: " << &ob << "임시 객체" << endl;
    return ob;
}

int main(void)
{
    SoSimple obj(7);    // 일반 객체
    SimpleFuncObj(obj); // 임시객채로 복사생성자 두번 호출 ( 매개변수, 리턴값 )
    cout << endl;

    SoSimple tempRef = SimpleFuncObj(obj);
    // 임시객채로 복사생성자 두번 호출 ( 매개변수, 리턴값 )
    // tempRef - 반환되는 임시객체에 tempRef란 이름을 할당
    cout << endl;

    cout << "Return Obj " << &tempRef << endl; // 반환된 임시객체에 할당한 것을 증명
    cout << endl;

    cout << "체크를 위한 친구" << endl;
    // 일반 객체, 참조되는 임시객체를 소멸 ( 소멸자 호출 )
    return 0;
}
